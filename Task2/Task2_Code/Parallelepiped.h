//
// Created by Vsevolod Melnik on 12.10.2021.
//

#ifndef TASK2_CODE_PARALLELEPIPED_H
#define TASK2_CODE_PARALLELEPIPED_H


#include <cstdio>
#include <cstdlib>
#include "Shape.h"

class Parallelepiped : public Shape {
private:
    int side1, side2, side3;

public:
    Parallelepiped(int side1, int side2, int side3);

    // Find surface's area.
    virtual double FindArea();

    // Input parallelepiped from file.
    static Shape* In(FILE * file);
    // Output parallelepiped to file.
    virtual void Out(FILE *file);

    // Initialize parallelepiped with random values.
    static Shape* InitRandom();
};


#endif //TASK2_CODE_PARALLELEPIPED_H
