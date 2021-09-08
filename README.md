# gtkshutdown #
A Shutdown Manager based on GTK+ 3

![Screenshot of version 0.2](https://i.imgur.com/hmmMu0Z.png)

## Building ##

#### Compile: ####

Ubuntu/Debian dependency: $<code>sudo apt install libgtk-3-dev libnotify-dev libcanberra-dev</code>

$<code>make</code>

#### Run: ####

$<code>make run</code>  or  $<code>cd build; ./gtkshutdown</code>


## Notes ##

* Supports all desktop enviroments that can run GTK+ 3.
* Uses GResource to be portable

## Features ##

* Logout, Restart, Shutdown
* Shedule timer for shutdown and restart
* Notification with alert sound when shutdown with timer

*In some distributions you might have to: Enable "Event Sounds" in Settings Manager -> Appearance -> Settings*

*[Submit your idea](https://github.com/giorgosioak/gtkshutdown/issues/new)*

## Developers ##

George Ioakeimidis <[giorgosioak95 at gmail.com](mailto:giorgosioak95@gmail.com?Subject=gtkshutdown)>

###### _This program is developed on Arch Linux in C and GTK+3 using [Glade](https://glade.gnome.org/) for ui._ ######
