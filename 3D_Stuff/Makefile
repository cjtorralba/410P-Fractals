CC=cc
CFLAGS= -lm -lX11 -pthread
DEBUG=-g

MAIN=Wire_Frame.cpp
EXECUTABLE=wire_frame


debug: $(MAIN)
	$(CC) $(MAIN) -o $(EXECUTABLE) $(CFLAGS) $(DEBUG)


all: $(MAIN)
	$(CC) $(MAIN) -o $(EXECUTABLE) $(CFLAGS) $(DEBUG)

clean:
	rm $(EXECUTABLE) *.bmp

run: $(EXECUTABLE)
	./$(EXECUTABLE)
