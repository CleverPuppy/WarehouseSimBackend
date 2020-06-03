#include "simserver.h"

char* MESSAGE = "Hello World";

SimServer::SimServer(char* addr, int port)
{
	base = event_base_new();
	if (!base) {
		fprintf(stderr, "Could not initialize libevent!\n");
		init_success = false;
	}

	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);

	listener = evconnlistener_new_bind(base,
		listener_cb,
		(void*)base,
		LEV_OPT_REUSEABLE | LEV_OPT_CLOSE_ON_FREE,
		-1,
		(sockaddr*)&sin,
		sizeof(sin));
	if (!listener) {
		fprintf(stderr, "Could not create a listener!\n");
		init_success = false;
	}

	event_base_dispatch(base);
}

SimServer::~SimServer()
{
	clear();
}

void SimServer::clear()
{
	evconnlistener_free(listener);
	event_base_free(base);

	printf("done\n");
}

void SimServer::run()
{
	if (init_success) {
		printf("SimServer::run\n");
		event_base_dispatch(base);
	}
	else {
		printf("Simserver::run failed\n");
	}
}

void SimServer::listener_cb(evconnlistener* listener, evutil_socket_t fd, struct sockaddr* sa, int socklen, void* user_data)
{
	event_base* base = static_cast<event_base*> (user_data);
	bufferevent* bev;

	bev = bufferevent_socket_new(base, fd, BEV_OPT_CLOSE_ON_FREE);
	if (!bev) {
		fprintf(stderr, "Error constructing bufferevent");
		event_base_loopbreak(base);
		return;
	}

	bufferevent_setcb(bev, conn_readcb, nullptr, conn_eventcb, nullptr);
	bufferevent_disable(bev, EV_WRITE);
	bufferevent_enable(bev, EV_READ);

	bufferevent_write(bev, MESSAGE, strlen(MESSAGE));
}


void SimServer::conn_readcb(bufferevent* bev, void* user_data)
{
	evbuffer* reader = bufferevent_get_input(bev);
	int len = evbuffer_get_length(reader);
	char buf[len];
	
	bufferevent_read(bev, buf, len);

	printf("read data : %s\n", buf);
}

void SimServer::conn_eventcb(bufferevent* bev, short events, void* user_data)
{
	if (events & BEV_EVENT_EOF) {
		printf("Connection closed.\n");
	}
	else if (events & BEV_EVENT_ERROR) {
		printf("Got an error on the connection: %s\n", strerror(errno));
	}

	bufferevent_free(bev);
}
