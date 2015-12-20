SERVER_EXE = server
CLIENT_EXE = client

COMPILER = /usr/bin/g++

#FLAGS = -DNDEBUG -g -O3 -ffast-math -std=c++11
FLAGS = -std=c++11

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.cpp
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

client:
	$(COMPILER) $(FLAGS) $(SRC) -o $(CLIENT_EXE)

server:
	$(COMPILER) $(FLAGS) $(SRC) -o $(SERVER_EXE)

clean:
	rm -f $(CLIENT_EXE) $(SERVER_EXE)
