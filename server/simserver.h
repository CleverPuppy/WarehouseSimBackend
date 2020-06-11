#pragma once
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <signal.h>
#ifndef _WIN32
#include <netinet/in.h>
#ifdef _XOPEN_SOURCE_EXTENDED
#include <arpa/inet.h>
#endif
#include <sys/socket.h>
#endif

#include <event2/bufferevent.h>
#include <event2/buffer.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>

#include "../common/utils.h"

// protobuf
#include "../common/robotmessage.pb.h"
#include "../common/messagehelper.h"

class SimServer : public noncopyable
{
public:
    struct event_base* base;
    struct evconnlistener* listener;

    struct sockaddr_in sin = { 0 };

#ifdef _WIN32
    WSADATA wsa_data;
    WSAStartup(0x0201, &wsa_data);
#endif

    SimServer(char* addr, int port);
    ~SimServer();
    void run();

private:
    // clean functions
    void clear();
    bool init_success;

    // callback functions
    static void listener_cb(evconnlistener* listener,
        evutil_socket_t fd,
        sockaddr* sa,
        int socklen,
        void* user_data);

    static void conn_readcb(bufferevent* bev,
        void* user_data);

    static void conn_eventcb(bufferevent* bev,
        short events,
        void* user_data); 
};