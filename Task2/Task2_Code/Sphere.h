//
// Created by Vsevolod Melnik on 12.10.2021.
//

#ifndef TASK2_CODE_SPHERE_H
#define TASK2_CODE_SPHERE_H


#include <cstdio>
#include <cstdlib>
#include "Shape.h"

class Sphere : public Shape {
private:
    // Radius of the sphere.
    double radius;

public:
    Sphere(int radius);

    // Find surface's area.
    virtual double FindArea();

    // Input sphere from file.
    static Shape* In(FILE *file);
    // Output sphere from file.
    virtual void Out(FILE *file);

    // Initialize sphere with random values.
    static Shape* InitRandom();
};


#endif //TASK2_CODE_SPHERE_H
