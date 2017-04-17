# Owner: George Ioakeimidis [ giorgosioak95@gmail.com ]
# This is a makefile for gtkshutdown
# URL < https://github.com/giorgosioak/gtkshutdown >

CFLAGS=-Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

all:
	gcc -o Shutdown\ Manager src/main.c $(CFLAGS)

rebuild: clean all
	
clean:
	rm -rf Shutdown\ Manager

add: clean
	git add .
	git status