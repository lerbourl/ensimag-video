#ifndef SYNCHRO_H
#define SYNCHRO_H

#include <stdbool.h>
#include <semaphore.h>
#include "ensitheora.h"

extern bool fini;

/* Les extern des variables pour la synchro ici */
sem_t smutex_hmap; // protection de la hash map

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
