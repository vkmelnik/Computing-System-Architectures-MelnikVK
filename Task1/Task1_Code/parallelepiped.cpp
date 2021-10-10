//
// Created by Vsevolod Melnik on 08.10.2021.
//

#include "parallelepiped.h"
#include <cstdlib>

// Find surface's area.
double FindArea(parallelepiped *p) {
    return (p->side1 * p->side2 + p->side1 * p->side3 + p->side2 * p->side3) * 2;
}

// Input parallelepiped from file.
void In(FILE * file, parallelepiped *p) {
    int a, b, c;
    fscanf (file, "%d %d %d", &a, &b, &c);
    p->side1 = a;
    p->side2 = b;
    p->side3 = c;
}

// Output parallelepiped to file.
void Out(FILE *file, parallelepiped *p) {
    fprintf(file, "Parallelepiped with sides %d, %d and %d", p->side1, p->side2, p->side3);
    printf("Parallelepiped with sides %d, %d and %d", p->side1, p->side2, p->side3);
}

// Initialize parallelepiped with random values.
void InitRandom(parallelepiped *p) {
    p->side1 = rand() % 1000;
    p->side2 = rand() % 1000;
    p->side3 = rand() % 1000;
}