all:
	gcc -o Shutdown\ Manager src/main.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
