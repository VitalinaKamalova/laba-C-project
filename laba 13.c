#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void new_sigabrt(int signal){
    printf("Received SIGABRT.");
    exit(1);
}

void new_sigfpe(int signal){
    printf("Received SIGFPE.");
    exit(1);
}

void new_sigill(int signal){
    printf("Received SIGILL.");
    exit(1);
}

void new_sigint(int signal){
    printf("Received SIGINT.");
    exit(1);
}

void new_sigsegv(int signal){
    printf("Received SIGSEGV.");
    exit(1);
}

void new_sigterm(int signal){
    printf("Received SIGTERM.");
    exit(1);
}

int main()
{   
    void (*funcptr)(int);
    funcptr = signal (SIGABRT, new_sigabrt);
    if (funcptr == SIG_IGN) signal(SIGABRT, SIG_IGN);
    funcptr = signal (SIGFPE, new_sigfpe);
    if (funcptr == SIG_IGN) signal(SIGFPE, SIG_IGN);
    funcptr = signal (SIGILL, new_sigill);
    if (funcptr == SIG_IGN) signal(SIGILL, SIG_IGN);
    funcptr = signal (SIGINT, new_sigint);
    if (funcptr == SIG_IGN) signal(SIGINT, SIG_IGN);
    funcptr = signal (SIGSEGV, new_sigsegv);
    if (funcptr == SIG_IGN) signal(SIGSEGV, SIG_IGN);
    funcptr = signal (SIGTERM, new_sigterm);
    if (funcptr == SIG_IGN) signal(SIGTERM, SIG_IGN);
    int n;
    scanf("%d", &n);
    raise(n);
    return 0;
}
