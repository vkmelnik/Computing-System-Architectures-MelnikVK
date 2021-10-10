//
// Created by Vsevolod Melnik on 08.10.2021.
//

#ifndef TASK1_SHAPE_H
#define TASK1_SHAPE_H

#include "sphere.h"
#include "tetrahedron.h"
#include "parallelepiped.h"

/*
 * Abstract shape.
 */

struct shape {
    enum ShapeType {
        Sphere,
        Parallelepiped,
        Tetrahedron,
    };

    // Density of that shape.
    double density;

    // Key that tells what kind of shape it is.
    ShapeType typeKey;

    union {
        sphere *s;
        parallelepiped *p;
        tetrahedron *t;
    };
};

// Find area of the shape's surface.
double FindArea(shape *s);

// Input shape from file.
void In(FILE * file, shape *s);
// Output shape to file.
void Out(FILE * file, shape *s);

// Initialize shape with random values.
void InitRandom(shape *s);

#endif //TASK1_SHAPE_H
