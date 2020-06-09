#include <event2/event.h>
#include <event2/util.h>
#include <cstdio>

#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <memory>
#include <cerrno>
#include <iostream>

#include "../messagehelper.h"

const char *HOST_IP = "127.0.0.1";
const int HOST_PORT = 9995;

template <typename SendMessage, typename RecvMessage>
class SimClientNoBuffer
{
public:
    SimClientNoBuffer();
    ~SimClientNoBuffer();
    void run();

private:
    int connection_watch_dog = 3;
    struct event_base *base;
    sockaddr_in sin{0};
    struct event *read_event;
    struct timeval timeout_val{5,0};
    evutil_socket_t fd;
    bool libevent_init_successful;
    void init();
    void clear();

    // handling socket related situation
    void conn_norespond_cb();
    void conn_error_cb();

    // cb functions
    static void read_cb(evutil_socket_t fd,
                        short what,
                        void *arg);
};
template <typename SendMessage, typename RecvMessage>
SimClientNoBuffer<SendMessage, RecvMessage>::SimClientNoBuffer()
{
    init();
}

template <typename SendMessage, typename RecvMessage>
SimClientNoBuffer<SendMessage, RecvMessage>::~SimClientNoBuffer()
{
    clear();
}
template <typename SendMessage, typename RecvMessage>
void SimClientNoBuffer<SendMessage, RecvMessage>::init()
{

    // init sockaddr
    sin.sin_family = AF_INET;
    sin.sin_port = htons(HOST_PORT);
    inet_aton(HOST_IP, &sin.sin_addr);

    // socket
    libevent_init_successful = true;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        fprintf(stderr, "SimClientNoBuffer:init:socket failed\n");
        libevent_init_successful = false;
    }
    else
    {
        // make socket noneblocking
        // evutil_make_socket_nonblocking(fd);
        // connect
        if (connect(fd, (sockaddr *)&sin, sizeof(sin)) < 0)
        {
            fprintf(stderr, "SimClientNoBuffer:init:connect error\n");
            libevent_init_successful = false;
        }
        // init libevent
        base = event_base_new();
        if (!base)
        {
            fprintf(stderr, "SimClientNoBuffer:init:event_base_new failed\n");
            libevent_init_successful = false;
        }
        // init event
        read_event = event_new(base, fd, EV_READ | EV_PERSIST | EV_TIMEOUT, read_cb, this);
        if(read_event){
            event_add(read_event, &timeout_val);
        }else{
            std::cout << "event_new error : " << strerror(errno) << std::endl;
        }
    }
}

template <typename SendMessage, typename RecvMessage>
void SimClientNoBuffer<SendMessage, RecvMessage>::clear()
{
    if (libevent_init_successful == true)
    {
        event_base_loopbreak(base);
    }
    if (read_event)
        event_free(read_event);
    if (base)
        event_base_free(base);
    evutil_closesocket(fd);
}


template<typename SendMessage, typename RecvMessage>
void SimClientNoBuffer<SendMessage, RecvMessage>::conn_norespond_cb() 
{
    #ifndef NODEBUG
    std::cout<< "read more than 3 times 0 bytes from socket , fd: " << event_get_fd(this->read_event)
        << ", to break loop and delete event " << std::endl;
    #endif 
    event_base_loopbreak(this->base);
    event_del(this->read_event);
    event_free(this->read_event);
    this->read_event = NULL;
    evutil_closesocket(fd);
}


template<typename SendMessage, typename RecvMessage>
void SimClientNoBuffer<SendMessage, RecvMessage>::conn_error_cb() 
{
    #ifndef NODEBUG
    std::cout << "conn_error_cb, fd: " << event_get_fd(this->read_event) 
        <<", error is : " << strerror(errno) << std::endl;
    #endif
    
}

template <typename SendMessage, typename RecvMessage>
void SimClientNoBuffer<SendMessage, RecvMessage>::run()
{
    if (libevent_init_successful)
    {
        event_base_dispatch(base);
    }
    else
    {
        fprintf(stderr, "SimClientNoBuffer:run: failed\n");
    }
}
template <typename SendMessage, typename RecvMessage>
void SimClientNoBuffer<SendMessage, RecvMessage>::read_cb(evutil_socket_t fd,
                                                          short what,
                                                          void *arg)
{
    #ifndef NDEBUG
    printf("Got an event on socket %d:%s%s%s%s\n",
           (int)fd,
           (what & EV_TIMEOUT) ? " timeout" : "",
           (what & EV_READ) ? " read" : "",
           (what & EV_WRITE) ? " write" : "",
           (what & EV_SIGNAL) ? " signal" : "");
    #endif
    
    SimClientNoBuffer<SendMessage, RecvMessage>* client = (SimClientNoBuffer<SendMessage, RecvMessage>*) arg;

    if (what & EV_READ)
    {
        RecvMessage _recv{};
        char msg[1000];
        size_t len = read(fd, (void *)msg, sizeof(msg));
        if (len > 0 && MessageHelper::parseFromArray(&_recv, (void *)msg, len))
        {
            printf("Simulate tobe coded !  \n");
            if (MessageHelper::sendScheduleRequestToFD(fd, 1110, 2, 3, 1.f) < 0)
            {
             std::cout << "sendScheduleRequestToFD failed : "
                << strerror(errno) << std::endl;               
            }
                //reset watch dog
            client -> connection_watch_dog = 3;
        }
        else if (len == 0)
        {
            // EOF
            client -> connection_watch_dog --;
            if(client->connection_watch_dog <= 0){
                client -> conn_norespond_cb();
                return;
            }
        }
        else
        {
            // -1 error
            #ifndef NDEBUG
            std::cout << "socket read return -1 , error is : " << strerror(errno) << std::endl;
            #endif
        }
    }
    else if (what & EV_TIMEOUT)
    {
        //  read timeout , should resend state msg
        if (MessageHelper::sendScheduleRequestToFD(fd, 1110, 1, 1, 1.f) < 0)
        {
            std::cout << "sendScheduleRequestToFD failed : "
                << strerror(errno) << std::endl;
        }
    }
}