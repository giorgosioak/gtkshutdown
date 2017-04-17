# Owner: George Ioakeimidis [ giorgosioak95@gmail.com ]
# This is a makefile for gtkshutdown
# URL < https://github.com/giorgosioak/gtkshutdown >

CFLAGS=-Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

all:
	mkdir -p build

	glib-compile-resources --sourcedir=data --generate-source data/gtkshutdown.gresource.xml

	gcc -o build/gtkshutdown src/main.c src/callbacks.c data/gtkshutdown.c $(CFLAGS)

run: all
	cd build; ./gtkshutdown

rebuild: clean all
	
clean:
	rm -rf build data/gtkshutdown.c

add: clean
	git add .
	git status
