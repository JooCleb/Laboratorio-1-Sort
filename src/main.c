#include <stdio.h>
#include <stdlib.h>

#include "statistics.h"
#include "generator.h"

void clear_screen() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void display_header() {
    printf("=====================================================\n");
    printf(" 📊  SISTEMA DE ANÁLISE DE ALGORITMOS DE ORDENAÇÃO  📊\n");
    printf("=====================================================\n\n");
}

int main() {
    srand((unsigned int)time(NULL));

    int *origin_vector = NULL;
    int *vector_test = NULL;
    int option = 0;
    int size_n = 0;

    do {
        display_header();

        if (size_n > 0 && origin_vector != NULL) {
            printf(" ⚙️  Status: Vetor de tamanho N = %d pronto!\n", size_n);
            printf("-----------------------------------------------------\n");
        } else {
            printf(" ⚠️ Status: Nenhum conjunto de dados gerado.\n");
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
        printf("  [8] Executar e comparar todos os algoritmos\n");
        printf("  [9] Encerrar o programa\n");
        printf("\n=====================================================\n");
        printf(" Digite uma opção: ");
        
        if (scanf("%d", &option) != 1) {
            printf("\n❌ Opção inválida! Tente novamente.\n");
            clear_screen();
            continue;
        }

        switch (option) {
            case 1:
                printf("\n--- ⚙️ Geração de Dados ---");
                printf("\n Digite o tamanho do vetor (N): ");
                scanf("%d", &size_n);

                if (size_n <= 0) {
                    printf("❌ Tamanho invalido! Insira um valor maior que 0.\n");
                    size_n = 0;
                    break;
                }

                origin_vector = (int*) realloc(origin_vector, size_n * sizeof(int));
                vector_test = (int*) realloc(vector_test, size_n * sizeof(int));

                if (origin_vector == NULL || vector_test == NULL) {
                    printf("❌ Erro ao alocar memória!\n");
                    exit(1);
                }

                int generation_type = 0;
                printf("\nEscolha o padrão dos dados:\n");
                printf("  [1] Dados Aleatórios\n");
                printf("  [2] Dados Previamente Ordenados\n");
                printf("  [3] Dados em Ordem Inversa\n");
                printf("  [4] Dados Parcialmente Ordenados\n");
                printf(" Digite uma opção: ");
                scanf("%d", &generation_type);

                switch (generation_type) {
                    case 1:
                         generate_random(origin_vector, size_n);
                         printf("\n ✅ Vetor aleatório gerado com sucesso!\n");
                         break;

                }

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