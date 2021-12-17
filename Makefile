CC = g++

CXXFLAGS = -Wall

SRCS = $(wildcard *.cpp)

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

INC = -I/backup/save/ProblemSolving/

TARGET = main

all: main

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $<

$(TARGET) : ${OBJS}
	echo $(SRCS)
	echo $(OBJS)
	echo $(DEPS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(TARGET) $(INC) $(LDFLAGS)
	make clean

.PHONY: clean all

clean:
	rm -rf $(OBJS) $(DEPS)

-include $(DEPS)