# Makefile for the client and server of the streaming UDP video program.

SERVER_EXE = server
CLIENT_EXE = client

COMPILER = /usr/bin/g++

CLIENT_SRC_FILES = main.cpp
SERVER_SRC_FILES = main.cpp

CLIENT_SRC_DIR = src/client
SERVER_SRC_DIR = src/server
CLIENT_SRC = $(addprefix $(CLIENT_SRC_DIR)/, $(CLIENT_SRC_FILES))
SERVER_SRC = $(addprefix $(SERVER_SRC_DIR)/, $(SERVER_SRC_FILES))

OBJ_DIR = obj

#FLAGS = -DNDEBUG -g -O3 -ffast-math -std=c++11
FLAGS = -std=c++11
OPENCV = $(shell pkg-config --cflags --libs opencv)

all: client server

client:
	@$(COMPILER) $(FLAGS) $(OPENCV) $(CLIENT_SRC) -o $(CLIENT_EXE)

server:
	@$(COMPILER) $(FLAGS) $(OPENCV) $(SERVER_SRC) -o $(SERVER_EXE)

clean:
	rm -f $(CLIENT_EXE) $(SERVER_EXE)
