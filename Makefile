#makefile for sound

all: testing

testing: simranS.cpp
	g++ simranS.cpp -otest \
	-D USE_OPENAL_SOUND \
	/usr/lib/x86_64-linux-gnu/libopenal.so \
	/usr/lib/x86_64-linux-gnu/libalut.so

clean:
	rm test 
