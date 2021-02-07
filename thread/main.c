#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int soma = 0;

void* somar_trapezio(void *tid) {
    // TODO realizar calculo

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    pthread_t threads[n];
    int status, i;
    void *thread_return;

    for (i = 0; i < n; i ++) {
        
        status = pthread_create(&threads[i], NULL, somar_trapezio, (void *)(size_t) i);

        if (status != 0) {
            printf("Erro na criação da thread. Código de erro: %d\n", status);
            return 1;
        }
    }
    
    pthread_join(threads[i - 1], &thread_return);
    printf("Soma = %d\n", soma);

    return 0;
}