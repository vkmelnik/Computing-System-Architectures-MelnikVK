//
// Created by Vsevolod Melnik on 08.10.2021.
//

#include "shape.h"
#include <cstdio>
#include <cstdlib>

// Input shape from file.
void In(FILE * file, shape *s) {
    int k;
    double d;
    fscanf(file, "%d", &k);
    fscanf(file, "%lf", &d);
    switch (k) {
        case 0:
            s->typeKey = shape::ShapeType::Sphere;
            s->s = new sphere;
            s->density = d;
            In(file, s->s);
            break;
        case 1:
            s->typeKey = shape::ShapeType::Parallelepiped;
            s->p = new parallelepiped;
            In(file, s->p);
            s->density = d;
            break;
        case 2:
            s->typeKey = shape::ShapeType::Tetrahedron;
            s->t = new tetrahedron;
            In(file, s->t);
            s->density = d;
            break;
        default:
            break;
    }
}

// Output shape to file.
void Out(FILE *file, shape *s) {
    switch(s->typeKey) {
        case shape::ShapeType::Sphere:
            Out(file, s->s);
            break;
        case shape::ShapeType::Parallelepiped:
            Out(file, s->p);
            break;
        case shape::ShapeType::Tetrahedron:
            Out(file, s->t);
            break;
        default:
            break;
    }
    fprintf(file, ", area %lf and density %lf \n", FindArea(s), s->density);
    printf(", area %lf and density %lf \n", FindArea(s), s->density);
}

// Find area of the shape's surface.
double FindArea(shape *s) {
    switch(s->typeKey) {
        case shape::ShapeType::Sphere:
            return FindArea(s->s);
        case shape::ShapeType::Parallelepiped:
            return FindArea(s->p);
        case shape::ShapeType::Tetrahedron:
            return FindArea(s->t);
        default:
            return 0;
    }
}

void InitRandom(shape *s) {
    int typeKey = rand() % 3;
    s->density = (double)rand() / RAND_MAX * 100.0;
    switch (typeKey) {
        case 0:
            s->typeKey = shape::ShapeType::Sphere;
            s->s = new sphere;
            InitRandom(s->s);
            break;
        case 1:
            s->typeKey = shape::ShapeType::Parallelepiped;
            s->p = new parallelepiped;
            InitRandom(s->p);
            break;
        case 2:
            s->typeKey = shape::ShapeType::Tetrahedron;
            s->t = new tetrahedron;
            InitRandom(s->t);
            break;
        default:
            break;
    }
}