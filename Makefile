CC     = gcc
CFLAGS = -c -g -Iinc/ -DTIME_STAMP
APP_PATH = app/
SRC_PATH = src/
BUILD_DIR = build/
all : main

main.o : $(APP_PATH)main.c
	$(CC) $(CFLAGS) $(APP_PATH)main.c

log.o : $(SRC_PATH)log.c
	$(CC) $(CFLAGS) $(SRC_PATH)log.c


main : $(SRC_PATH)log.o $(APP_PATH)main.o
	mkdir build
	$(CC) -o $(BUILD_DIR)main $(SRC_PATH)*.o $(APP_PATH)*.o
 
clean :
	rm -rf build $(SRC_PATH)*.o $(APP_PATH)*.o
