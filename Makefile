# Owner: George Ioakeimidis [ giorgosioak95@gmail.com ]
# This is a makefile for gtkshutdown
# URL < https://github.com/giorgosioak/gtkshutdown >

CFLAGS=-Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

all:
	mkdir -p build
	cp src/window_main.glade build/
	gcc -o build/gtkshutdown src/main.c src/callbacks.c $(CFLAGS)
	glib-compile-resources --sourcedir=src src/gtkshutdown.gresource.xml
	mv src/gtkshutdown.gresource build/

run: all
	cd build; ./gtkshutdown

rebuild: clean all
	
clean:
	rm -rf build

add: clean
	git add .
	git status
