#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <SDL2/SDL.h>
#include <pthread.h>

#include "stream_common.h"
#include "oggstream.h"

int main(int argc, char *argv[]) {
    int res;

    if (argc != 2) {
	fprintf(stderr, "Usage: %s FILE", argv[0]);
	exit(EXIT_FAILURE);
    }
    assert(argc == 2);


    // Initialisation de la SDL
    res = SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_EVENTS);
    atexit(SDL_Quit);
    assert(res == 0);

    // start the two stream readers
    // theoraStreamReader video
    pthread_create(&videoStream_pid, NULL, theoraStreamReader, (void*)argv[1]);
    // vorbisStreamReader audio
    pthread_create(&audioStream_pid, NULL, vorbisStreamReader, (void*)argv[1]);
    // wait audio thread terminaison de vorbis
    pthread_join(audioStream_pid, NULL);
    // 1 seconde de garde pour le son,
    sleep(1);
    // tuer les deux threads videos si ils sont bloqués
    pthread_cancel(videoStream_pid);
    pthread_cancel(sdlStream_pid);
    // attendre les 2 threads videos
    pthread_join(videoStream_pid, NULL);
    pthread_join(sdlStream_pid, NULL);

    exit(EXIT_SUCCESS);
}
