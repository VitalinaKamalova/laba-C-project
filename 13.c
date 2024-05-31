#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void sig_handler(int signum) {
    switch (signum) {
        case SIGABRT:
            printf("Received SIGABRT signal.\n");
            break;
        case SIGFPE:
            printf("Received SIGFPE signal.\n");
            break;
        case SIGILL:
            printf("Received SIGILL signal.\n");
            break;
        case SIGINT:
            printf("Received SIGINT signal.\n");
            break;
        case SIGSEGV:
            printf("Received SIGSEGV signal.\n");
            break;
        case SIGTERM:
            printf("Received SIGTERM signal.\n");
            break;
        default:
            printf("Received unknown signal: %d\n", signum);
            break;
    }
}

int main() {
    // установка констант
    signal(SIGABRT, sig_handler);
    signal(SIGFPE, sig_handler);
    signal(SIGILL, sig_handler);
    signal(SIGINT, sig_handler);
    signal(SIGSEGV, sig_handler);
    signal(SIGTERM, sig_handler);

    printf("Enter signal number to raise (0-15): ");
    int signum;
    scanf("%d", &signum);

    // вызов сигнала
    raise(signum);

    return 0;
}
