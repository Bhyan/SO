#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define A 0.0
#define B 10.0

double v_resultado[7] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int indice_resultado = 0;

typedef struct valores_locais {
    double local_a;
    double local_b;
    double local_n;
    double local_h;
} valores_locais;

double f_reta(double valor_x) {
    return 5.0;
}

double f_seno(double valor_x) {
    return 418.9829 * 2.0 - valor_x * sin(sqrt(valor_x));
}

void* chama_threads(valores_locais *v_locais) {
    double area = 0.0;

    for (int i = 0; i < v_locais -> local_n; i ++) {
        area += f_reta(v_locais -> local_a + i * v_locais -> local_h);
    }

    v_resultado[indice_resultado++] = area;

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    double h, area = 0.0;
    int threads_size = atoi(argv[1]);
    int n = atoi(argv[2]);
    pthread_t threads[threads_size];
    int status;
    struct valores_locais v_locais[threads_size];

    h = (B - A) / n;
    // area += (f_reta(A) + f_reta(B)) / 2.0;

    v_locais[0].local_n = n / threads_size;
    v_locais[0].local_a = A;
    v_locais[0].local_b = B / threads_size;

    for (int i = 0; i < threads_size; i ++) {

        status = pthread_create(&threads[i], NULL, (void*)chama_threads, (void *)(size_t) &v_locais);

        v_locais[i + 1].local_n = v_locais[0].local_n;
        v_locais[i + 1].local_a = v_locais[0].local_a + v_locais[0].local_b;
        v_locais[i + 1].local_b = v_locais[0].local_b * i;

        printf("N %.2f\n", v_locais[i].local_n);
        printf("A %.2f\n", v_locais[i].local_a);
        printf("B %.2f\n", v_locais[i].local_b);

        if (status != 0) {
            printf("Erro na criação da thread. Código de erro: %d\n", status);
            return 1;
        }
    }
    
    for (int i = 0; i < threads_size; i++) {
        pthread_join(threads[i], NULL);
        area += v_resultado[i];
    }
    
    printf("Área = %.1e\n", area * h);

    return 0;
}