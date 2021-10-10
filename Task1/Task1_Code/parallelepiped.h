//
// Created by Vsevolod Melnik on 08.10.2021.
//

#ifndef TASK1_PARALLELEPIPED_H
#define TASK1_PARALLELEPIPED_H

#include<cstdio>

/*
 * Parallelepiped.
 */

struct parallelepiped {
    int side1, side2, side3;
};

// Find surface's area.
double FindArea(parallelepiped *p);

// Input parallelepiped from file.
void In(FILE * file, parallelepiped *p);
// Output parallelepiped to file.
void Out(FILE *file, parallelepiped *p);

// Initialize parallelepiped with random values.
void InitRandom(parallelepiped *p);

#endif //TASK1_PARALLELEPIPED_H
