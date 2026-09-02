#include "generator.hpp"

#include <iostream>
#include <random>

void generate_random(std::vector<int> &v) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(v.size() * 10));

    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = dist(gen);
    }
}

void generate_ordered(std::vector<int> &v) {
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = static_cast<int>(i);
    }
}

void generate_inverse(std::vector<int> &v) {
    int n = static_cast<int>(v.size());
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = n - static_cast<int>(i);
    }
}

void generate_partially_ordered(std::vector<int> &v) {
    size_t limit = static_cast<size_t>(v.size() * 0.8);
    for (size_t i = 0; i < limit; ++i) {
        v[i] = static_cast<int>(i);
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(v.size() * 10));

    for (size_t i = limit; i < v.size(); ++i) {
        v[i] = dist(gen);
    }
}

void display_vector(const std::vector<int> &v) {
    if (v.size() > 100) {
        std::cout << "[Vetor muito grande para exibir na tela (" << v.size() << " elementos)]\n";
        return;
    }
    std::cout << "[ ";
    for (int elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "]\n";
}