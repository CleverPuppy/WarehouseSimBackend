outdir = out

src = $(wildcard ./*.cpp)
obj = $(patsubst %.cpp, $(outdir)/%.o,$(src))
#obj=$(src:%.cpp:%.o)
src_proto = $(wildcard ./protobuf/*.cc)
obj_proto = $(patsubst %.cc,$(outdir)/%.o,$(src_proto))

src_client = $(wildcard ./client/*.cpp)
obj_client = $(patsubst %.cpp, $(outdir)/%.o,$(src_client)) messagehelper.o


target_server = server_app
target_client = client_app
targets = $(target_server) $(target_client)
CC = g++
COMPILE_ARGS = -Wall -ggdb
all:$(targets)

$(target_server):$(obj) $(obj_proto)
	$(CC)  $(COMPILE_ARGS) $(obj) $(obj_proto) -o $(outdir)/$(target_server) -levent -levent_core -lprotobuf

$(target_client):$(obj_client) $(obj_proto)
	$(CC)  $(COMPILE_ARGS) $(obj_client) $(obj_proto) -o $(outdir)/$(target_client) -levent -levent_core -lprotobuf

$(outdir)/%.o: %.cpp
	$(CC) $(COMPILE_ARGS) -c $< -o $@

$(outdir)/%.o: %.cc
	$(CC) $(COMPILE_ARGS) -c $< -o $@

# %.o: %.c
# 	$(CC) -c $< -o $@

clean:
	rm -rf $(outdir)/*.o $(outdir)/client/*.o $(outdir)/protobuf/*.o $(outdir)/target_client $(outdir)/target_server