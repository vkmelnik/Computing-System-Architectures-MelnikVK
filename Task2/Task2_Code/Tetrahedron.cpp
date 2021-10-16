//
// Created by Vsevolod Melnik on 12.10.2021.
//

#include "Tetrahedron.h"
#include <cmath>

Tetrahedron::Tetrahedron(int side) {
    this->side = side;
}

double Tetrahedron::FindArea() {
    return sqrt(3) * side * side;
}

Shape* Tetrahedron::In(FILE *file) {
    int s;
    fscanf (file, "%d", &s);
    return new Tetrahedron(s);
}

void Tetrahedron::Out(FILE *file) {
    fprintf(file, "Tetrahedron with side %d", side);
    printf("Tetrahedron with side %d", side);
}

Shape* Tetrahedron::InitRandom() {
    return new Tetrahedron(rand() % 1000);
}
