//
// Created by Vsevolod Melnik on 12.10.2021.
//

#include "Shape.h"
#include "Sphere.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"

Shape* Shape::In(FILE *file) {
    int k;
    double d;
    fscanf(file, "%d", &k);
    fscanf(file, "%lf", &d);
    Shape* s;
    switch (k) {
        case 0:
            s = Sphere::In(file);
            s->density = d;
            break;
        case 1:
            s = Parallelepiped::In(file);
            s->density = d;
            break;
        case 2:
            s = Tetrahedron::In(file);
            s->density = d;
            break;
        default:
            break;
    }
    return s;
}

Shape* Shape::InitRandom() {
    Shape *s = nullptr;
    int typeKey = rand() % 3;
    switch (typeKey) {
        case 0:
            s = Sphere::InitRandom();
            break;
        case 1:
            s = Parallelepiped::InitRandom();
            break;
        case 2:
            s = Tetrahedron::InitRandom();
            break;
        default:
            break;
    }
    s->density = (double)rand() / RAND_MAX * 100.0;
    return s;
}

