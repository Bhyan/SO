#include <math.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define A 0.0
#define B 10.0

double v_resultado[6] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
int indice_resultado = 0;

typedef struct valores_locais {
  double local_a;
  double local_b;
  double local_n;
  double local_h;
} valores_locais;

double f_reta(double valor_x) { return 5.0; }

void *chama_threads(valores_locais *v_locais) {
  double area = 0.0;

  for (int i = 0; i < v_locais->local_n; i++) {
    area += f_reta(v_locais->local_a + i * v_locais->local_h);
  }

  v_resultado[indice_resultado++] = area;

  pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
  double h, area = 0.0;
  int threads_size = atoi(argv[1]);
  double n = atof(argv[2]);
  pthread_t threads[threads_size];
  int status;
  struct valores_locais v_locais[threads_size];

  h = (B - A) / n;

  area = (f_reta(A) + f_reta(B)) / 2;

  for (int i = 0; i < threads_size; i++) {

    status = pthread_create(&threads[i], NULL, (void *)chama_threads,
                            (void *)(size_t)&v_locais);

    v_locais[i].local_n = (n / threads_size) * (i + 1);
    v_locais[i].local_a = h * (i + 1);
    v_locais[i].local_h = h;

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