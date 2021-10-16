//
// Created by Vsevolod Melnik on 12.10.2021.
//

#ifndef TASK2_CODE_TETRAHEDRON_H
#define TASK2_CODE_TETRAHEDRON_H

#include <cstdio>
#include <cstdlib>
#include "Shape.h"

class Tetrahedron : public Shape {
private:
    int side;

public:
    Tetrahedron(int side);

    // Find surface's area.
    virtual double FindArea();

    // Input tetrahedron from the file.
    static Shape* In(FILE * file);
    // Output tetrahedron to the file.
    virtual void Out(FILE *file);

    // Initialize tetrahedron with random values.
    static Shape* InitRandom();
};


#endif //TASK2_CODE_TETRAHEDRON_H
