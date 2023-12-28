//
// Created by matdz on 12/27/2023.
//

#include "moderator.h"
#include "..//kviz.h"
#include "sockety/passive_socket.h"
#include "sockety/active_socket.h"
#include <stdlib.h>
#include <pthread.h>

int main(int argc, char** argv) {
    //inicializacia premennych
    pthread_mutex_t mutexPrihlasenie = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t condOdhlasovane = PTHREAD_COND_INITIALIZER;
    pthread_cond_t condOtazka = PTHREAD_COND_INITIALIZER;

    PASSIVE_SOCKET passiveSocket;
    passive_socket_init(&passiveSocket);
    passive_socket_start_listening(&passiveSocket, 12345);

    return 0;
}
