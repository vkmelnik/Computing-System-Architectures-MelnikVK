//
// Created by Vsevolod Melnik on 15.10.2021.
//

#include "Container.h"

Container *Container::In(FILE *file) {
    Container* c = new Container();
    int k;
    fscanf(file, "%d", &k);
    if (k < c->maxLength) {
        c->length = k;
        for (int i = 0; i < c->length; ++i)
            c->shapes[i] = Shape::In(file);
    } else {
        printf("Reading error: too many shapes.");
    }
    return c;
}

void Container::Out(FILE *file) {
    fprintf(file, "%d shapes:", length);
    printf("%d shapes:", length);
    for (int i = 0; i < length; ++i) {
        fprintf(file, "\n");
        printf("\n");
        shapes[i]->Out(file);
    }
}

Container *Container::InitRandom(int cnt) {
    Container* c = new Container();
    if (cnt > Container::maxLength) {
        printf("Too much shapes were requested. The program will generate only %d\n", Container::maxLength);
        cnt = Container::maxLength;
    }
    int numberOfShapes = cnt;
    c->length = numberOfShapes;
    for (int i = 0; i < numberOfShapes; ++i) {
        c->shapes[i] = Shape::InitRandom();
    }
    return c;
}

void Container::DeleteLessThenAverage() {
    double averageArea = 0;
    for (int i = 0; i < length; ++i)
        averageArea += shapes[i]->FindArea();
    if (length <= 0)
        return;
    averageArea /= length;
    int lastToStay = 0;
    for (int i = 0; i < length; ++i) {
        if (shapes[i]->FindArea() >= averageArea)
            shapes[lastToStay++] = shapes[i];
    }
    length = lastToStay;
}
