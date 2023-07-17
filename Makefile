CC = g++
TARGET = main
OBJS = main.o bf.o
CXXFLAGS = -O2 -Wall -Wextra -std=c++2b

.PHONY: all
all: $(TARGET)

.PHONY: clean
clean:
	rm -rf *.o $(TARGET)

$(TARGET): $(OBJS) Makefile
	$(CC) $(OBJS) $(LIBS) $(LDFLAGS) -o $@

%.o: %.cpp Makefile
	$(CC) $(CXXFLAGS) -c $<