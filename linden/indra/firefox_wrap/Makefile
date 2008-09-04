objects = ff_wrap.o ffwshell.o ffwunix.o
CFLAGS  = -Igecko-sdk/include/ -I../../libraries/i686-linux/include/ -I../../libraries/i686-linux/include/glib-2.0/ -I../../libraries/i686-linux/include/gtk-2.0/ -I../../libraries/i686-linux/include/pango-1.0/ -I../../libraries/i686-linux/include/atk-1.0/ -Ipluginsdk_include/

MOZLIBS = -lplds4 -lplc4 -lnspr4
NPPSRC  = np_entry.cpp  npn_gate.cpp  npp_gate.cpp 
           
libffwrap.so: $(objects)
	g++ $(CFLAGS) -lSDL -lgtk-x11-2.0 -lgdk-x11-2.0 -lglib-2.0 -lgobject-2.0 -fshort-wchar -pthread -pipe -Lgecko-sdk/lib/ $(MOZLIBS) -Wall -fPIC -shared -Wl,-z,defs -Wl,-h,$@ -o $@ ff_wrap.o $(NPPSRC) ffwshell.o ffwunix.o -Wl,-rpath-link,gecko-sdk/lib

$(objects): %.o: %.c
	gcc -c $(CFLAGS) $< -o $@

all: libffwrap.so

clean:
	rm -f $(objects)
	rm -f n*.o
	rm -f libffwrap.so








#g++ -q -fno-tree-pre -fno-tree-fre -fno-rtti -fno-exceptions -Wall -Wconversion -Wpointer-arith -Wcast-align -Woverloaded-virtual -Wsynth -Wno-ctor-d
#tor-privacy -Wno-non-virtual-dtor -Wno-long-long -pedantic -fshort-wchar -pthread -pipe  -DNDEBUG -DTRIMMED -O -D_GNU_SOURCE=1 -D_REENTRANT -I/usr/include/S
#DL -I/usr/include/gtk-2.0 -I/usr/lib/gtk-2.0/include -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/glib-2.0 -I/usr/lib
#/glib-2.0/include   -fPIC -shared -Wl,-z,defs -Wl,-h,libnullplugin.so -o libnullplugin.so  npshell.o nullplugin.o npunix.o       -L../../../../../dist/bin -
#Wl,-rpath-link,../../../../../dist/bin -lxpcom -lxul   -L/home/gareth/SecondLife_i686_1_20_15_92456/app_settings/mozilla-runtime-linux-i686/ -lplds4 -lplc4
#-lnspr4 -lpthread -ldl -lXt  -lSDL -lGL -lGLU -L/lib   -lgtk-x11-2.0 -lgdk-x11-2.0 -latk-1.0 -lgdk_pixbuf-2.0 -lm -lpangocairo-1.0 -lpango-1.0 -lcairo -lgob
#ject-2.0 -lgmodule-2.0 -ldl -lglib-2.0    -lX11  -ldl -lm
