#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void new_sigabrt(int sig){
    printf("Received SIGABRT!");
    exit(1);
}

void new_sigfpe(int sig){
    printf("Received SIGFPE!!");
    exit(1);
}

void new_sigill(int sig){
    printf("Received SIGILL!");
    exit(1);
}

void new_sigint(int sig){
    printf("Received SIGINT!");
    exit(1);
}

void new_sigabrt(int sig){
    printf("Received SIGSEGV!");
    exit(1);
}

void new_sigabrt(int sig){
    printf("Received SIGABRT!");
    exit(1);
}
