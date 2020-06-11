#pragma once
#include <event2/event.h>
#include <event2/listener.h>
#include <event2/util.h>
#include <event2/event.h>
#include <iostream>
#include <errno.h>
#include <stdio.h>
#include <string.h>

class EnvManager
{
public:
    EnvManager(event_base* base);
    ~EnvManager();

public:
    void listen();

    bool libevent_init_success = false;
    /* ------------------------------ libevent args ----------------------------- */
    struct event_base* base;
    struct evconnlistener *listener;
    sockaddr_in sin{0};
    /* -------------------------------------------------------------------------- */

public:
    static struct timeval timeout_val;
    static void listener_cb(struct evconnlistener *listener,
                            evutil_socket_t fd,
                            struct sockaddr *sa,
                            int socklen, void *data);
    static void read_cb(evutil_socket_t fd,
                    short what,
                    void* data);
};