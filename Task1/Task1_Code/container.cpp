//
// Created by Vsevolod Melnik on 08.10.2021.
//

#include <cstdio>
#include "container.h"
#include <cstdlib>

// Input shapes from file.
void In(FILE * file, container *c) {
    int k;
    fscanf(file, "%d", &k);
    if (k < c->maxLength) {
        c->length = k;
        for (int i = 0; i < c->length; ++i)
            In(file, &(c->shapes[i]));
    } else {
        printf("Reading error: too many shapes.");
    }
}

// Output shapes from file.
void Out(FILE * file, container *c) {
    fprintf(file, "%d shapes:\n", c->length);
    printf("%d shapes:\n", c->length);
    for (int i = 0; i < c->length; ++i) {
        fprintf(file, "  ");
        printf("  ");
        Out(file, &(c->shapes[i]));
    }
}

// Create random shapes and fill the container with them.
void InitRandom(container *c) {
    int numberOfShapes = rand() % c->maxLength;
    c->length = numberOfShapes;
    for (int i = 0; i < numberOfShapes; ++i) {
        InitRandom(&(c->shapes[i]));
    }
}

// Function number 19: delete shapes, which area is less than average.
void DeleteLessThenAverage(container *c) {
    double averageArea = 0;
    for (int i = 0; i < c->length; ++i)
        averageArea += FindArea(&(c->shapes[i]));
    if (c->length <= 0)
        return;
    averageArea /= c->length;
    int lastToStay = 0;
    for (int i = 0; i < c->length; ++i) {
        if (FindArea(&(c->shapes[i])) >= averageArea)
            c->shapes[lastToStay++] = c->shapes[i];
    }
    c->length = lastToStay;
}