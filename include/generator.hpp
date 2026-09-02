#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <vector>

void generate_random(std::vector<int> &v);
void generate_ordered(std::vector<int> &v);
void generate_inverse(std::vector<int> &v);
void generate_partially_ordered(std::vector<int> &v);

void display_vector(const std::vector<int> &v);

#endif 