#include <iostream>
#include <vector>
#include <limits>

#include "statistics.hpp"
#include "generator.hpp"

void clear_input_buffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void display_header() {
    std::cout << "=====================================================\n";
    std::cout << " 📊  SISTEMA DE ANÁLISE DE ALGORITMOS DE ORDENAÇÃO  📊\n";
    std::cout << "=====================================================\n\n";
}

int main() {
    std::vector<int> origin_vector;
    std::vector<int> vector_test;
    int option = 0;

    do {
        display_header();

        if (!origin_vector.empty()) {
            std::cout << " ⚙️  Status: Vetor de tamanho N = " << origin_vector.size() << " pronto!\n";
            std::cout << "-----------------------------------------------------\n";
        } else {
            std::cout << " ⚠️ Status: Nenhum conjunto de dados gerado.\n";
            std::cout << "-----------------------------------------------------\n";
        }

        std::cout << "\n 📌 MENU DE OPÇÕES:\n\n";
        std::cout << "  [1] Gerar conjunto de dados\n";
        std::cout << "  [2] Exibir dados gerados\n";
        std::cout << "  [3] Executar Selection Sort\n";
        std::cout << "  [4] Executar Insertion Sort\n";
        std::cout << "  [5] Executar Shell Sort\n";
        std::cout << "  [6] Executar Quick Sort\n";
        std::cout << "  [7] Executar Heap Sort\n";
        std::cout << "  [8] Executar e comparar todos os algoritmos\n";
        std::cout << "  [9] Encerrar o programa\n";
        std::cout << "\n=====================================================\n";
        std::cout << " Digite uma opção: ";
        
        if (!(std::cin >> option)) {
            std::cout << "\n❌ Opção inválida! Tente novamente.\n";
            clear_input_buffer();
            continue;
        }

        switch (option) {
            case 1: {
                int size_n = 0;
                std::cout << "\n--- ⚙️  Geração de Dados ---\n";
                std::cout << "\n Digite o tamanho do vetor (N): ";
                std::cin >> size_n;

                if (size_n <= 0) {
                    std::cout << "❌ Tamanho inválido! Insira um valor maior que 0.\n";
                    break;
                }

                origin_vector.resize(size_n);

                int generation_type = 0;
                std::cout << "\nEscolha o padrão dos dados:\n";
                std::cout << "  [1] Dados Aleatórios\n";
                std::cout << "  [2] Dados Previamente Ordenados\n";
                std::cout << "  [3] Dados em Ordem Inversa\n";
                std::cout << "  [4] Dados Parcialmente Ordenados\n";
                std::cout << " Digite uma opção: ";
                std::cin >> generation_type;

                switch (generation_type) {
                    case 1:
                        generate_random(origin_vector);
                        std::cout << "\n ✅ Vetor aleatório gerado com sucesso!\n";
                        break;
                    case 2: 
                        generate_ordered(origin_vector);
                        std::cout << "\n ✅ Vetor ordenado gerado com sucesso!\n";
                        break;
                    case 3:
                        generate_inverse(origin_vector);
                        std::cout << "\n ✅ Vetor inverso gerado com sucesso!\n";
                        break;
                    case 4:
                        generate_partially_ordered(origin_vector);
                        std::cout << "\n ✅ Vetor parcialmente ordenado gerado com sucesso!\n";
                        break;
                    default:
                        std::cout << "\n ❌ Opção inválida! Gerando vetor aleatório por padrão.\n";
                        generate_random(origin_vector);
                        break;
                }
                break;
            }

            case 2:
                if (origin_vector.empty()) {
                    std::cout << "\n--- ⚠️ Nenhum dado foi gerado ainda. Escolha a opção 1 primeiro!\n";
                } else {
                    std::cout << "\n--- ⚙️ Conteúdo do Vetor Original ---\n";
                    display_vector(origin_vector);
                }
                break;

            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
                if (origin_vector.empty()) {
                    std::cout << "\n⚠️ Você precisa GERAR OS DADOS (Opção 1) antes de rodar os testes!\n";
                } else {
                    std::cout << " [EM BREVE] Executando algoritmo(s)...\n";
                }
                break;

            case 9:
                std::cout << " 👋 Saindo do programa... Até logo!\n";
                break;

            default:
                std::cout << " ❌ Opção inválida! Tente novamente.\n";
                break;
        }

    } while (option != 9);

    return 0;
}