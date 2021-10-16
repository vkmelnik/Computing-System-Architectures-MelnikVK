//
// Created by Vsevolod Melnik on 12.10.2021.
//

#ifndef TASK2_CODE_SHAPE_H
#define TASK2_CODE_SHAPE_H

#include <cstdio>
#include <cstdlib>

// Abstract shape class.
class Shape {
protected:
    // Density of the shape.
    double density;

public:
    // Area of the shape's surface.
    virtual double FindArea() = 0;

    // Input shape from file.
    static Shape* In(FILE * file);
    // Output shape to file.
    virtual void Out(FILE * file) = 0;

    // Initialize shape with random values.
    static Shape* InitRandom();
};


#endif //TASK2_CODE_SHAPE_H
