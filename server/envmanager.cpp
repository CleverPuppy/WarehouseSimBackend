#include "envmanager.h"
#define ENVPORT 9996

EnvManager::EnvManager(event_base* base)
    :base(base)
{
    if(base == nullptr){
        fprintf(stderr,"error : base is null\n");
    }
}

void EnvManager::listen() 
{
    if(base == nullptr){
        libevent_init_success = false;
        return;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(ENVPORT);

    if(listener){
        evconnlistener_free(listener);
    }else{
        listener = evconnlistener_new_bind(
            base,
            listener_cb,
            (void*)base,
            LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,
            -1,
            (sockaddr*)&sin,
            sizeof(sin));
        if(!listener){
            fprintf(stderr,"Could not create a listener\n");
            libevent_init_success = false;
        }else{
            
        }
    }
}

struct timeval EnvManager::timeout_val{1,0};
void EnvManager::listener_cb(struct evconnlistener *listener,
                            evutil_socket_t fd,
                            struct sockaddr *sa,
                            int socklen, void *data) 
{
    EnvManager* manager = (EnvManager*)data;
    event* readEvent = event_new(manager->base,fd,EV_READ | EV_TIMEOUT, read_cb,data);
    if(event_add(readEvent,&timeout_val) < 0){
    #ifndef NODEBUG
    std::cout << "listener_cb:event_add error:"
        << strerror(errno) << std::endl;
    #endif
    }
}


void EnvManager::read_cb(evutil_socket_t fd,
                    short what,
                    void* data) 
{
    EnvManager* manager =  (EnvManager*)data;
    // TODO parsedata from socket
    // TODO generate data to socket
}