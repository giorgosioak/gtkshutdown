# Owner: George Ioakeimidis [ giorgosioak95@gmail.com ]
# This is a makefile for gtkshutdown
# URL < https://github.com/giorgosioak/gtkshutdown >

DESTDIR ?=
PREFIX ?= /usr

CFLAGS=-Wall `pkg-config --cflags --libs gtk+-3.0 libnotify libcanberra` -export-dynamic -no-pie

all:
	mkdir -p build

	glib-compile-resources --sourcedir=data --generate-source data/gtkshutdown.gresource.xml

	gcc -o build/gtkshutdown src/main.c src/callbacks.c src/utilities.c data/gtkshutdown.c $(CFLAGS)

run: all
	cd build; ./gtkshutdown

rebuild: clean all

install: all
	install -Dm 755 build/gtkshutdown $(DESTDIR)/$(PREFIX)/bin/gtkshutdown
	
uninstall:
	rm -f $(DESTDIR)/$(PREFIX)/bin/gtkshutdown
	
clean:
	rm -rf build data/gtkshutdown.c

add: clean
	git add .
	git status
