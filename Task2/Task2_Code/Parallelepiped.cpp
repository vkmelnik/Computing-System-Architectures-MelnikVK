//
// Created by Vsevolod Melnik on 12.10.2021.
//

#include "Parallelepiped.h"

double Parallelepiped::FindArea() {
    return (side1 * side2 + side1 * side3 + side2 * side3) * 2;
}

Shape* Parallelepiped::In(FILE *file) {
    int a, b, c;
    fscanf (file, "%d %d %d", &a, &b, &c);
    return new Parallelepiped(a, b, c);
}

void Parallelepiped::Out(FILE *file) {
    fprintf(file, "Parallelepiped with sides %d, %d and %d", side1, side2, side3);
    printf("Parallelepiped with sides %d, %d and %d", side1, side2, side3);
}

Shape* Parallelepiped::InitRandom() {
    return new Parallelepiped(rand() % 1000, rand() % 1000, rand() % 1000);
}

Parallelepiped::Parallelepiped(int side1, int side2, int side3) {
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}
