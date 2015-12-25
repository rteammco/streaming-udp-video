# Makefile for the client and server of the streaming UDP video program.

SERVER_EXE = server
CLIENT_EXE = client

COMPILER = /usr/bin/g++

SHARED_SRC = $(wildcard src/*.cpp)
CLIENT_SRC = $(wildcard src/client/*.cpp)
SERVER_SRC = $(wildcard src/server/*.cpp)
SRC_INCLUDE = -I src

OBJ_DIR = obj

#FLAGS = -DNDEBUG -g -O3 -ffast-math -std=c++11
FLAGS = -std=c++11
OPENCV = $(shell pkg-config --cflags --libs opencv)

all: client server

client:
	@$(COMPILER) $(FLAGS) $(OPENCV) $(SRC_INCLUDE) $(SHARED_SRC) $(CLIENT_SRC) -o $(CLIENT_EXE)

server:
	@$(COMPILER) $(FLAGS) $(OPENCV) $(SRC_INCLUDE) $(SHARED_SRC) $(SERVER_SRC) -o $(SERVER_EXE)

clean:
	rm -f $(CLIENT_EXE) $(SERVER_EXE)
