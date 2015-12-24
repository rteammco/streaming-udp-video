SERVER_EXE = server
CLIENT_EXE = client

COMPILER = /usr/bin/g++

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.cpp
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

#FLAGS = -DNDEBUG -g -O3 -ffast-math -std=c++11
FLAGS = -std=c++11
OPENCV = $(shell pkg-config --cflags --libs opencv)

all: client server

client:
	$(COMPILER) $(FLAGS) $(OPENCV) $(SRC) -o $(CLIENT_EXE)

server:
	$(COMPILER) $(FLAGS) $(OPENCV) $(SRC) -o $(SERVER_EXE)

clean:
	rm -f $(CLIENT_EXE) $(SERVER_EXE)
