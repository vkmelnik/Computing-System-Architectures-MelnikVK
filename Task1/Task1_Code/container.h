//
// Created by Vsevolod Melnik on 08.10.2021.
//

/*
 * Container of shapes.
 */

#ifndef TASK1_CONTAINER_H
#define TASK1_CONTAINER_H

#include "shape.h"

// Struct that describes container of shapes.
struct container {
    static const int maxLength = 10000;
    int length = 0;
    // Array of shapes of maximum length.
    shape shapes[maxLength];
};

// Input shapes from file.
void In(FILE * file, container *c);
// Output shapes from file.
void Out(FILE * file, container *c);

// Create random shapes and fill the container with them.
void InitRandom(container *c);

// Function number 19: delete shapes, which area is less than average.
void DeleteLessThenAverage(container *c);

#endif //TASK1_CONTAINER_H
