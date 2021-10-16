//
// Created by Vsevolod Melnik on 12.10.2021.
//

#include "Sphere.h"

double Sphere::FindArea() {
    const double pi = 3.14159265359;
    return 4 * pi * radius * radius;
}

Shape* Sphere::In(FILE *file) {
    double r;
    fscanf (file, "%lf", &r);
    return new Sphere(r);
}

Shape* Sphere::InitRandom() {
    return new Sphere((double)rand() / RAND_MAX * 100.0);
}

void Sphere::Out(FILE *file) {
    fprintf(file, "Sphere with radius %lf", radius);
    printf("Sphere with radius %lf", radius);
}

Sphere::Sphere(int radius) {
    this->radius = radius;
}

