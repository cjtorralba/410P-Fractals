CC=cc
CFLAGS= -lm -lX11 -pthread
DEBUG=-g

MAIN=main.cpp
SERP=serp_triangle.cpp
PRACTICE=practice.cpp
TRIANGLE=serp_triangle.cpp
EXECUTABLE=main


debug: $(MAIN)
	$(CC) $(MAIN) $(SERP) -o $(EXECUTABLE) $(CFLAGS) $(DEBUG)


all: $(MAIN)
	$(CC) $(MAIN) -o $(EXECUTABLE) $(CFLAGS)

clean:
	rm $(EXECUTABLE) *.bmp

run: $(EXECUTABLE)
	./$(EXECUTABLE)




