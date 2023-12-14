#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "hrac.h"
#include "moderator.h"
#include "kviz.h"

int main(int args, char **argv) {
    int pocetHracov = 3;
    int pocetOtazok = 10;
    if (args > 1) {
        pocetHracov = atoi(argv[1]);
        if (args > 2){
            pocetOtazok = atoi(argv[2]);
        }
    }

    //inicializacia premennych
    pthread_mutex_t mutexPrihlasenie = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t condOdhlasovane = PTHREAD_COND_INITIALIZER;
    pthread_cond_t condOtazka = PTHREAD_COND_INITIALIZER;

    //inicializacia moderatora
    MODERATOR moderatorData = {pocetOtazok, pocetHracov, mutexPrihlasenie, condOtazka, condOdhlasovane};
    pthread_t moderator;
    pthread_create(&moderator, NULL, moderuj, &moderatorData);

    //inicializacia hracov
    HRAC hraciData[pocetHracov];
    for (int i = 0; i < pocetHracov; ++i) {
        hraciData[i].id = i;
        hraciData[i].pocetHracov = pocetHracov;
        hraciData[i].mutexPrihlasenie = mutexPrihlasenie;
        hraciData[i].condOtazka = condOtazka;
        hraciData[i].condOdhlasovane = condOdhlasovane;
    }

    pthread_t hraci[pocetHracov];
    for (int i = 0; i < pocetHracov; ++i) {
        pthread_create(&hraci[i], NULL, hraj, &hraciData[i]);
    }

    //cakanie na skoncenie kvizu
    pthread_join(moderator, NULL);
    for (int i = 0; i < pocetHracov; ++i) {
        pthread_join(hraci[i], NULL);
    }

    //znicenie premennych
    pthread_cond_destroy(&condOdhlasovane);
    pthread_cond_destroy(&condOtazka);
    pthread_mutex_destroy(&mutexPrihlasenie);
    return 0;
}
