CC = g++
CFLAGS = -I./src/include
SRCS = src/util.cpp src/configfsisomanager.cpp src/main.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = isodrive

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)

.PHONY: all clean

