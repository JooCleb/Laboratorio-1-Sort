#include <stdio.h>
#include <stdlib.h>

#include "generator.h"

void generate_random(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = rand() % (n * 10);
    }
}

void generate_ordered(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = i;
    }
}

void generate_inverse(int *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = n - i;
    }
}

void generate_partially_ordered(int *v, int n) {
    int limite = (int)(n * 0.8); 
    for (int i = 0; i < limite; i++) {
        v[i] = i;
    }
    for (int i = limite; i < n; i++) {
        v[i] = rand() % (n * 10);
    }
}

void copy_vector(const int *origem, int *destino, int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

void display_vector(const int *v, int n) {
    if (n > 100) {
        printf("[Vetor muito grande para exibir na tela (%d elementos)]\n", n);
        return;
    }
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("]\n");
}