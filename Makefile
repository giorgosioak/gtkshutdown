# Owner: George Ioakeimidis [ giorgosioak95@gmail.com ]
# This is a makefile for gtkshutdown
# URL < https://github.com/giorgosioak/gtkshutdown >

CFLAGS=-Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

all:
	gcc -o gtkshutdown src/main.c src/callbacks.c $(CFLAGS)

run: all
	./gtkshutdown

rebuild: clean all
	
clean:
	rm -rf gtkshutdown

add: clean
	git add .
	git status
