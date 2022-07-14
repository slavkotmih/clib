CURRENT_DIR = $(shell pwd)

# set optimization flag
CXX_FLAG = O3
ifneq ($(flag),)
CXX_FLAG := $(flag)
endif

include 	= $(CURRENT_DIR)/include
src			= $(CURRENT_DIR)/src
lib			= $(CURRENT_DIR)/lib

####################################
# container
container_c 	= $(src)/container.c
container_o 	= container.o
container_so 	= $(lib)/libcontainer.so

container_obj: $(container_c)
	gcc -Wall -$(CXX_FLAG) -fPIC \
	-I $(include) \
	-c $(container_c) \
	-o $(container_o)

container_so: container_obj
	gcc -Wall -$(CXX_FLAG) -shared \
	-o $(container_so) $(container_o)
	rm $(container_o)
####################################

####################################
# tree
tree_c 	= $(src)/tree.c
tree_o 	= tree.o
tree_so 	= $(lib)/libtree.so

tree_obj: $(tree_c)
	gcc -Wall -$(CXX_FLAG) -fPIC \
	-I $(include) \
	-c $(tree_c) \
	-o $(tree_o)

tree_so: tree_obj
	gcc -Wall -$(CXX_FLAG) -shared \
	-o $(tree_so) $(tree_o)
	rm $(tree_o)
####################################

####################################
# allocator_std
allocator_std_c 	= $(src)/allocator_std.c
allocator_std_o 	= allocator_std.o
allocator_std_so 	= $(lib)/liballocator_std.so

allocator_std_obj: $(allocator_std_c)
	gcc -Wall -$(CXX_FLAG) -fPIC \
	-I $(include) \
	-c $(allocator_std_c) \
	-o $(allocator_std_o)

allocator_std_so: allocator_std_obj
	gcc -Wall -$(CXX_FLAG) -shared \
	-o $(allocator_std_so) $(allocator_std_o)
	rm $(allocator_std_o)
####################################

####################################
# algorithm
algorithm_c 	= $(src)/algorithm.c
algorithm_o 	= algorithm.o
algorithm_so 	= $(lib)/libalgorithm.so

algorithm_obj: $(algorithm_c)
	gcc -Wall -$(CXX_FLAG) -fPIC \
	-I $(include) \
	-c $(algorithm_c) \
	-o $(algorithm_o)

algorithm_so: algorithm_obj
	gcc -Wall -$(CXX_FLAG) -shared \
	-o $(algorithm_so) $(algorithm_o)
	rm $(algorithm_o)
####################################

####################################
# list
list_c 	= $(src)/list.c
list_o 	= list.o
list_so 	= $(lib)/liblist.so

list_obj: $(list_c)
	gcc -Wall -$(CXX_FLAG) -fPIC \
	-I $(include) \
	-c $(list_c) \
	-o $(list_o)

list_so: list_obj
	gcc -Wall -$(CXX_FLAG) -shared \
	-o $(list_so) $(list_o)
	rm $(list_o)
####################################

####################################
# test
test_c = $(CURRENT_DIR)/test/test.c
test_o = $(CURRENT_DIR)/test/test.o
test_exe = $(CURRENT_DIR)/test/test

test_obj: $(test_c)
	gcc -Wall -$(CXX_FLAG) \
	-I $(include) \
	-c $(test_c) \
	-o $(test_o)

test_exe: test_obj
	gcc -Wall -$(CXX_FLAG) \
	-o $(test_exe) $(test_o) \
	-L$(lib) -lcontainer -ltree -lallocator_std -lm
	rm $(test_o)
# ========================
####################################
