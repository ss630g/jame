//
#include <stdio.h>
#include <cstdlib>
//#include <string>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#ifdef USE_OPENAL_SOUND
#include </usr/include/AL/alut.h>
#endif

void sound (const char *a) 
{
#ifdef USE_OPENAL_SOUND

    alutInit(0, NULL);
    if (alGetError() != AL_NO_ERROR) {
	printf(" There is an error  in alutInit()\n");
	return;
    }

    alGetError();

    float termoil[6] = {0.0, 0.0, 1.0, 0.0, 1.0, 0.0};
    alListener3f(AL_POSITION, 0.0, 0.0, 0.0);
    alListenerfv(AL_ORIENTATION, termoil);
    alListenerf(AL_GAIN, 1.0);

    ALuint toom;
    toom = alutCreateBufferFromFile(a); 

    ALuint tum;
    
    alGenSources(1, &tum);
    alSourcei(tum, AL_BUFFER, toom);

    alSourcef(tum, AL_GAIN, 1.0);
    alSourcef(tum, AL_PITCH, 1.0);
    alSourcei(tum, AL_LOOPING, AL_FALSE);

    if (alGetError() != AL_NO_ERROR) {
	printf("cannot set the source\n");
	return;
    }

    for (int index = 0; index < 4; index++) {
	alSourcePlay(tum);
	usleep(250000);
    }

    alDeleteSources(1, &tum);
    alDeleteBuffers(1, &toom);

    ALCcontext *stuff = alcGetCurrentContext();
    ALCdevice *yantar = alcGetContextsDevice(stuff);

    alcMakeContextCurrent(NULL);
    alcDestroyContext(stuff);
    alcCloseDevice(yantar);

#endif
}

int main()
{
    sound("./g.wav");
    return 0;
}

