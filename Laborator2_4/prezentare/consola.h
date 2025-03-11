//
// Created by lupse on 3/11/2025.
//

#ifndef CONSOLA_H
#define CONSOLA_H

#include "../domain/lista.h"

void run();
void printComenzi();
void printMedicamente(VectorDynamic* v);
int citesteInt(int* valoare, const char* prompt);
int citesteFloat(float* valoare, const char* prompt);
int citesteString(char* valoare, const char* prompt);
int citesteChar(char* valoare, const char* prompt);
#endif //CONSOLA_H
