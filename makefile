outdir = out

src_common = $(wildcard ./common/*.cpp ./common/*.cc)
obj_common = $(patsubst %.cpp %.cc, $(outdir)/%.o,$(src_common))
#obj=$(src:%.cpp:%.o)
# src_proto = $(wildcard ./common/*.cc)
# obj_proto = $(patsubst %.cc,$(outdir)/%.o,$(src_proto))

src_client = $(wildcard ./client/*.cpp)
obj_client = $(patsubst %.cpp, $(outdir)/%.o,$(src_client))

src_server = $(wildcard ./server/*.cpp)
obj_server = $(patsubst %.cpp, $(outdir)/%.o,$(src_server))

target_server = server_app
target_client = client_app
targets = $(target_server) $(target_client)
CC = g++
COMPILE_ARGS = -Wall -ggdb
all:$(targets)

$(target_server):$(obj_server) $(obj_common)
	$(CC)  $(COMPILE_ARGS) $(obj_server) $(obj_common) -o $(outdir)/$(target_server) -levent -levent_core -lprotobuf -pthread

$(target_client):$(obj_client) $(obj_common)
	$(CC)  $(COMPILE_ARGS) $(obj_client) $(obj_common) -o $(outdir)/$(target_client) -levent -levent_core -lprotobuf -pthread

$(outdir)/%.o: %.cpp
	$(CC) $(COMPILE_ARGS) -c $< -o $@

$(outdir)/%.o: %.cc
	$(CC) $(COMPILE_ARGS) -c $< -o $@

# %.o: %.c
# 	$(CC) -c $< -o $@

clean:
	rm -rf $(outdir)/*.o $(outdir)/client/*.o $(outdir)/common/*.o $(outdir)/server/*.o $(outdir)/target_client $(outdir)/target_server