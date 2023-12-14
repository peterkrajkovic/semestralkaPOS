//
// Created by petok on 14. 12. 2023.
//
#include <pthread.h>
#include <stdio.h>
#include "moderator.h"


void *moderuj(void *data) {
    MODERATOR *d = (MODERATOR *)data;
    printf("Zacina sa kviz. Dnes tu mame %d hracov.", d->pocetHracov);
}