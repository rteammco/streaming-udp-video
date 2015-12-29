# Makefile for the sender and receiver of the streaming UDP video program.

SEND_EXE = sender
RECV_EXE = receiver

COMPILER = /usr/bin/g++

SHARED_SRC = $(wildcard src/*.cpp)
RECV_SRC = $(wildcard src/receiver/*.cpp)
SEND_SRC = $(wildcard src/sender/*.cpp)
SRC_INCLUDE = -I src

OBJ_DIR = obj

#FLAGS = -DNDEBUG -g -O3 -ffast-math -std=c++11
FLAGS = -std=c++11
OPENCV = $(shell pkg-config --cflags --libs opencv)

all: receiver sender

receiver:
	@$(COMPILER) $(FLAGS) $(SRC_INCLUDE) $(SHARED_SRC) $(RECV_SRC) -o $(RECV_EXE) $(OPENCV)

sender:
	@$(COMPILER) $(FLAGS) $(SRC_INCLUDE) $(SHARED_SRC) $(SEND_SRC) -o $(SEND_EXE) $(OPENCV)

clean:
	rm -f $(RECV_EXE) $(SEND_EXE)
