#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t filho1, filho2, neto1, neto2;

    printf("Pai PID = %d nasceu.\n", getpid());

    sleep(14);
    
    filho1 = fork();  
    if(!filho1) {
        
        printf("Filho PID = %d nasceu.\n", getpid());
        
        sleep(12);

        neto1 = fork();
        if(!neto1) {
            printf("Neto PID = %d nasceu.\n", getpid());

            sleep(12);

            printf("Neto PID = %d morreu aos 12 anos.\n", getpid());
            
            exit(0);
           
        }
        sleep(18);

        printf("Filho PID = %d morreu aos 30 anos.\n", getpid());

        exit(0);
    }

    sleep(2);
    filho2 = fork();
    if(!filho2) {

        printf("Filho PID = %d nasceu.\n", getpid());

        sleep(14);
        neto2 = fork();
        if(!neto2) {

            printf("Neto PID = %d nasceu.\n", getpid());

            sleep(18);

            printf("Neto PID = %d morreu aos 18 anos.\n", getpid());

            exit(0);
           
        }

        sleep(16);

        printf("Filho PID = %d morreu aos 30 anos.\n", getpid());

        exit(0);
    }

    sleep(44);

    printf("Pai PID = %d morreu aos 60 anos.\n", getpid());

    return 0;
}