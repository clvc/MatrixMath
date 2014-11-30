
all: main

main: libTron19Matrix.so main.cpp
	g++ -o main -Wl,-rpath,. -L./ main.cpp -lTron19Matrix

libTron19Matrix.so: matrix.cpp matrix.h
	g++ -shared -fPIC -Wl,-soname,libTron19Matrix.so -o libTron19Matrix.so matrix.cpp
