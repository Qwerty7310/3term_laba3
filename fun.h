#ifndef INC_3TERM_LABA3_FUN_H
#define INC_3TERM_LABA3_FUN_H

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int get_random_number(int, int);
void random_sequence(int, int*);
void random_sequence(int, int*, int*);

void ascending_sequence(int, int*);
void ascending_sequence(int, int*, int*);

void descending_sequence(int, int*);
void descending_sequence(int, int*, int*);

void selection_sort(int, int*, int&, int&, bool);
void shell_sort (int, int*, int&, int&, bool);
void selection_sort(int, int*, int&, int&);
void shell_sort (int, int*, int&, int&);
void print_array(int, int*);

#endif //INC_3TERM_LABA3_FUN_H
