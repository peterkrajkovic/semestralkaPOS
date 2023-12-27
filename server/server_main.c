//
// Created by matdz on 12/27/2023.
//

#include "moderator.h"
#include <pthread.h>

int main(int argc, char** argv) {
    int pocetHracov = 3;
    int pocetOtazok = 10;
    if (argc > 1) {
        pocetHracov = atoi(argv[1]);
        if (argc > 2){
            pocetOtazok = atoi(argv[2]);
        }
    }

    return 0;
}
