//
// Created by Vsevolod Melnik on 15.10.2021.
//

#ifndef TASK2_CODE_CONTAINER_H
#define TASK2_CODE_CONTAINER_H

#include <cstdio>
#include "Shape.h"

class Container {
private:
    static const int maxLength = 10000;
    int length = 0;
    // Array of shapes of maximum length.
    Shape* shapes[maxLength];

public:
    // Input shapes from file.
    static Container* In(FILE * file);
    // Output shapes from file.
    void Out(FILE * file);

    // Create random shapes and fill the container with them.
    static Container* InitRandom(int cnt);

    // Function number 19: delete shapes, which area is less than average.
    void DeleteLessThenAverage();
};


#endif //TASK2_CODE_CONTAINER_H
