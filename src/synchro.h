#ifndef SYNCHRO_H
#define SYNCHRO_H

#include <stdbool.h>
#include <semaphore.h>
#include <pthread.h>
#include "ensitheora.h"

extern bool fini;

/* Les extern des variables pour la synchro ici */
pthread_mutex_t mutex_hmap, mutex_textures;
sem_t sem_taille, sem_fenetre_texture, sem_free_cache, sem_cache;
/* Fonctions de synchro à implanter */

void envoiTailleFenetre(th_ycbcr_buffer buffer);
void attendreTailleFenetre();

void attendreFenetreTexture();
void signalerFenetreEtTexturePrete();

void debutConsommerTexture();
void finConsommerTexture();

void debutDeposerTexture();
void finDeposerTexture();

#endif
