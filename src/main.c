#include <stdio.h>
#include <stdlib.h>

#include "statistics.h"

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void display_header() {
    printf("=====================================================\n");
    printf(" 📊  SISTEMA DE ANÁLISE DE ALGORITMOS DE ORDENAÇÃO  📊\n");
    printf("=====================================================\n\n");
}

int main() {
    int option = 0;
    int size_n = 0;

    do {
        clear_screen();
        display_header();

        if (size_n > 0) {
            printf(" ⚙️  size atual do vetor (N): %d elementos\n", size_n);
            printf("-----------------------------------------------------\n");
        } else {
            printf(" ⚠️  Nenhum vetor configurado no momento.\n");
            printf("-----------------------------------------------------\n");
        }

        printf("\n 📌 MENU DE OPÇÕES:\n\n");
        printf("  [1] Gerar conjunto de dados\n");
        printf("  [2] Exibir dados gerados\n");
        printf("  [3] Executar Selection Sort\n");
        printf("  [4] Executar Insertion Sort\n");
        printf("  [5] Executar Shell Sort\n");
        printf("  [6] Executar Quick Sort\n");
        printf("  [7] Executar Heap Sort\n");
        printf("  [8] Executar e comparar TODOS os algoritmos\n");
        printf("  [9] Encerrar o programa\n");
        printf("\n=====================================================\n");
        printf(" Digite sua opção: ");
        
        if (scanf("%d", &option) != 1) {
            option = 0;
        }

        printf("\n");

        switch (option) {
            case 1:
                printf(" [EM BREVE] Módulo de geração de dados...\n");
                printf("\n Digite o size N desejado para testar o menu: ");
                scanf("%d", &size_n);
                printf(" size alterado para %d!\n", size_n);
                break;

            case 2:
                printf(" [EM BREVE] Visualização do vetor...\n");
                break;

            case 3:
                printf(" [EM BREVE] Executando Selection Sort...\n");
                break;

            case 4:
                printf(" [EM BREVE] Executando Insertion Sort...\n");
                break;

            case 5:
                printf(" [EM BREVE] Executando Shell Sort...\n");
                break;

            case 6:
                printf(" [EM BREVE] Executando Quick Sort...\n");
                break;

            case 7:
                printf(" [EM BREVE] Executando Heap Sort...\n");
                break;

            case 8:
                printf(" [EM BREVE] Rodando benchmark completo...\n");
                break;

            case 9:
                printf(" 👋 Saindo do programa... Até logo!\n");
                break;

            default:
                printf(" ❌ Opção inválida! Tente novamente.\n");
                break;
        }

        if (option != 9) {
            printf("\n Pressione ENTER para continuar...");
            getchar(); 
            getchar();
        }

    } while (option != 9);

    return 0;
}