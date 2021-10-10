//
// Created by Vsevolod Melnik on 08.10.2021.
//

#ifndef TASK1_TETRAHEDRON_H
#define TASK1_TETRAHEDRON_H

#include<cstdio>

/*
 * Tetrahedron with equal sides.
 */

struct tetrahedron {
    int side;
};

// Find surface's area.
double FindArea(tetrahedron *t);

// Input tetrahedron from the file.
void In(FILE * file, tetrahedron *t);
// Output tetrahedron to the file.
void Out(FILE *file, tetrahedron *t);

// Initialize tetrahedron with random values.
void InitRandom(tetrahedron *t);

#endif //TASK1_TETRAHEDRON_H