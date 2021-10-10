//
// Created by Vsevolod Melnik on 08.10.2021.
//

#ifndef TASK1_SPHERE_H
#define TASK1_SPHERE_H

#include <cstdio>

/*
 * Sphere with radius.
 */

struct sphere {
    double radius;
};

// Find surface's area.
double FindArea(sphere *s);

// Input sphere from file.
void In(FILE *file, sphere *s);
// Output sphere from file.
void Out(FILE *file, sphere *s);

// Initialize sphere with random values.
void InitRandom(sphere *s);

#endif //TASK1_SPHERE_H