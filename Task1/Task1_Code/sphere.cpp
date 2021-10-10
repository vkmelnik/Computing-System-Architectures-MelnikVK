//
// Created by Vsevolod Melnik on 08.10.2021.
//

#include "sphere.h"
#include <cstdio>
#include <cstdlib>

// Find surface's area.
double FindArea(sphere *s) {
    const double pi = 3.14159265359;
    return 4 * pi * s->radius * s->radius;
}

// Input sphere from file.
void In(FILE * file, sphere *s) {
    double r;
    fscanf (file, "%lf", &r);
    s->radius = r;
}

// Output sphere from file.
void Out(FILE * file, sphere *s) {
    fprintf(file, "Sphere with radius %lf", s->radius);
    printf("Sphere with radius %lf", s->radius);
}

// Initialize sphere with random values.
void InitRandom(sphere *s) {
    s->radius = (double)rand() / RAND_MAX * 100.0;
}