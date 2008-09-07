objects = ff_wrap.o ffwshell.o ffwunix.o
CFLAGS  = -Igecko-sdk/include/ -I../../libraries/i686-linux/include/ -I../../libraries/i686-linux/include/glib-2.0/ -I../../libraries/i686-linux/include/gtk-2.0/ -I../../libraries/i686-linux/include/pango-1.0/ -I../../libraries/i686-linux/include/atk-1.0/ -Ipluginsdk_include/

MOZLIBS = -lplds4 -lplc4 -lnspr4
NPPSRC  = np_entry.cpp  npn_gate.cpp  npp_gate.cpp 
           
libffwrap.so: $(objects)
	g++ $(CFLAGS) -lX11 -lSDL -lgtk-x11-2.0 -lgdk-x11-2.0 -lglib-2.0 -lgobject-2.0 -fshort-wchar -pthread -pipe -Lgecko-sdk/lib/ $(MOZLIBS) -Wall -fPIC -shared -Wl,-z,defs -Wl,-h,$@ -o $@ ff_wrap.o $(NPPSRC) ffwshell.o ffwunix.o -Wl,-rpath-link,gecko-sdk/lib

$(objects): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@

all: libffwrap.so

clean:
	rm -f $(objects)
	rm -f n*.o
	rm -f libffwrap.so
