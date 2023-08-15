#ifndef MORSEGENIUS_HEADER_H
#define MORSEGENIUS_HEADER_H

#include <stdio.h>

void header() {
    //printf("\n");
    printf("\033[1m\033[32m _____                      _____            _           \033[0m\n");
    printf("\033[1m\033[32m|     | ___  ___  ___  ___ |   __| ___  ___ |_| _ _  ___ \033[0m\n");
    printf("\033[1m\033[32m| | | || . ||  _||_ -|| -_||  |  || -_||   || || | ||_ -|\033[0m\n");
    printf("\033[1m\033[32m|_|_|_||___||_|  |___||___||_____||___||_|_||_||___||___|\033[0m\n");
    printf("\n[\033[1m\033[33m!\033[0m] 1.0.0\n");
    printf("[\033[1m\033[33m!\033[0m] github.com/nmap02\n");
    printf("\033[0m");
}

#endif
