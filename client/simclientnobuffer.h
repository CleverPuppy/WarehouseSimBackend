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
    struct event_base *base;
    sockaddr_in sin{0};
    struct event *read_event;
    struct timeval timeout_val{5,0};
    evutil_socket_t fd;
    bool libevent_init_successful;
    void init();
    void clear();


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
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        fprintf(stderr, "SimClientNoBuffer:init:socket failed\n");
        libevent_init_successful = false;
        return;
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
            return;
        }
        // init libevent
        base = event_base_new();
        if (!base)
        {
            fprintf(stderr, "SimClientNoBuffer:init:event_base_new failed\n");
            libevent_init_successful = false;
            return;
        }
        // init event
        read_event = event_new(base, fd, EV_READ | EV_PERSIST | EV_TIMEOUT, read_cb, this);
        event_add(read_event, &timeout_val);
    }
}

template <typename SendMessage, typename RecvMessage>
void SimClientNoBuffer<SendMessage, RecvMessage>::clear()
{
    if (libevent_init_successful == true)
    {
        event_base_loopbreak(base);
    }
        evutil_closesocket(fd);
    if (read_event)
        event_free(read_event);
    if (base)
        event_base_free(base);
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
    

    if(what & EV_READ){
        RecvMessage _recv{};
        char msg[1000];
        size_t len = read(fd,(void*)msg,sizeof(msg));
        if(len > 0 && MessageHelper::parseFromArray(&_recv,(void*)msg,len))
        {
            printf("Simulate tobe coded !  \n");
            if(MessageHelper::sendScheduleRequestToFD(fd,1110,2,3,1.f) < 0){
             std::cout << "sendScheduleRequestToFD failed : "
                << strerror(errno) << std::endl;               
            }
        }
        else if(len == 0){
            // EOF
        }else{
            // -1 error
        }
    }else if(what & EV_TIMEOUT){
        //  read timeout , should resend state msg
        if(MessageHelper::sendScheduleRequestToFD(fd,1110,1,1,1.f) < 0 ){
            std::cout << "sendScheduleRequestToFD failed : "
                << strerror(errno) << std::endl;
        }
    }
}