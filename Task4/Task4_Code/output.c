//------------------------------------------------------------------------------
// output.c - единица компиляции, вбирающая в себя все функции вывода данных
//------------------------------------------------------------------------------

#include <stdio.h>

#include "extdata.h"

// Вычисление периметра сферы
double AreaSphere(void *s);
// Вывод параметров сферы в файл
void OutSphere(void *s, FILE *ofst) {
    fprintf(ofst, "It is Sphere: r = %d. Area = %g\n", *((int*)s), AreaSphere(s));
}

// Вычисление периметра тетраэдра
double AreaTetrahedron(void *t);
// Вывод параметров тетраэдра в файл
void OutTetrahedron(void *t, FILE *ofst) {
    fprintf(ofst, "It is Tetrahedron: a = %d. Area = %g\n", *((int*)t), AreaTetrahedron(t));
}

// Вычисление периметра параллелепипеда
double AreaParallelepiped(void *t);
// Вывод параметров параллелепипеда в файл
void OutParallelepiped(void *t, FILE *ofst) {
    fprintf(ofst, "It is Parallelepiped: a = %d, b = %d, c = %d. Area = %g\n", *((int*)t), *((int*)(t+intSize)), *((int*)(t+2*intSize)), AreaParallelepiped(t));
}

// Вывод параметров текущей фигуры в поток
void OutShape(void *s, FILE *ofst) {
    int k = *((int*)s);
    if(k == SPHERE) {
        OutSphere(s+intSize, ofst);
    }
    else if(k == PARALLELEPIPED) {
        OutParallelepiped(s+intSize, ofst);
    }
    else if (k == TETRAHEDRON) {
        OutTetrahedron(s+intSize, ofst);
    }
    else {
        fprintf(ofst, "Incorrect figure!\n");
    }
}

// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst) {
    void *tmp = c;
    fprintf(ofst, "Container contains %d elements.\n", len);
    for(int i = 0; i < len; i++) {
        fprintf(ofst, "%d: ", i);
        OutShape(tmp, ofst);
        tmp = tmp + shapeSize;
    }
}
