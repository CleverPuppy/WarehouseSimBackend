outdir = out

src = $(wildcard ./*.cpp)
obj = $(patsubst %.cpp, $(outdir)/%.o,$(src))
#obj=$(src:%.cpp:%.o)
src_proto = $(wildcard ./*.cc)
obj_proto = $(patsubst %.cc,$(outdir)/%.o,$(src_proto))


target = app
CC = g++

$(target):$(obj) $(obj_proto)
	$(CC) $(obj) $(obj_proto) -o $(outdir)/$(target) -levent -levent_core -lprotobuf

$(outdir)/%.o: %.cpp
	$(CC) -c $< -o $@

$(outdir)/%.o: %.cc
	$(CC) -c $< -o $@

# %.o: %.c
# 	$(CC) -c $< -o $@

clean:
	rm -rf *.o $(target)