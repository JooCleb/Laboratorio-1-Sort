#ifndef generator_H
#define generator_H

void generate_random(int *v, int n);
void generate_ordered(int *v, int n);
void generate_inverse(int *v, int n);
void generate_partially_ordered(int *v, int n);

void copy_vector(const int *origin, int *destination, int n);
void display_vector(const int *v, int n);

#endif 