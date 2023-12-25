//
// Created by petok on 14. 12. 2023.
//

#ifndef HRAC_H
#define HRAC_H

#include <pthread.h>
#include <stdio.h>

typedef struct Hrac {
    int id;
    int pocetOtazok;
    pthread_mutex_t mutexPrihlasenie;
    pthread_cond_t condOtazka;
    pthread_cond_t condOdhlasovane;
} HRAC;

void* hraj(void* data);

#endif //HRAC_H
