//
// Created by Vsevolod Melnik on 08.10.2021.
//

#include "tetrahedron.h"
#include <cmath>

// Find surface's area.
double FindArea(tetrahedron *t) {
    return sqrt(3) * t->side * t->side;
}

// Input tetrahedron from the file.
void In(FILE * file, tetrahedron *t) {
    int s;
    fscanf (file, "%d", &s);
    t->side = s;
}

// Output tetrahedron to the file.
void Out(FILE * file, tetrahedron *t) {
    fprintf(file, "Tetrahedron with side %d", t->side);
    printf("Tetrahedron with side %d", t->side);
}

// Initialize tetrahedron with random values.
void InitRandom(tetrahedron *t) {
    t->side = rand() % 1000;
}
