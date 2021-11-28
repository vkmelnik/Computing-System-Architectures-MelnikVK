//------------------------------------------------------------------------------
// inrnd.c - единица компиляции, вбирающая функции генерации случайных данных
//------------------------------------------------------------------------------

#include <stdlib.h>

#include "extdata.h"

// rnd.c - содержит генератор случайных чисел в диапазоне от 1 до 20
int Random() {
    return rand() % 20 + 1;
}

// Случайный ввод параметров сферы
void InRndSphere(void *s) {
    int x = Random();
    *((int*)s) = x;
}

// Случайный ввод параметров тетраэдра
void InRndTetrahedron(void *t) {
    int x = Random();
    *((int*)t) = x;
}

// Случайный ввод параметров тетраэдра
void InRndParallelepiped(void *p) {
    int x = Random();
    *((int*)p) = x;
    int y = Random();
    *((int*)(p+intSize)) = y;
    int z = Random();
    *((int*)(p+2*intSize)) = z;
}

// Случайный ввод обобщенной фигуры
int InRndShape(void *s) {
    int k = rand() % 2 + 1;
    switch(k) {
        case 1:
            *((int*)s) = SPHERE;
            InRndSphere(s+intSize);
            return 1;
        case 2:
            *((int*)s) = TETRAHEDRON;
            InRndTetrahedron(s+intSize);
            return 1;
        case 3:
            *((int*)s) = PARALLELEPIPED;
            InRndParallelepiped(s+intSize);
            return 1;
        default:
            return 0;
    }
}

// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size) {
    void *tmp = c;
    while(*len < size) {
        if(InRndShape(tmp)) {
            tmp = tmp + shapeSize;
            (*len)++;
        }
    }
}
