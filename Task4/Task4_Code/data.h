#ifndef __data__
#define __data__

//------------------------------------------------------------------------------
// data.h - Описание данных бестиповой программы
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Раздел констант
//------------------------------------------------------------------------------

// Константа, определяющая размер целого числа
int const intSize = sizeof(int);
// Константа, задающая размер для сферы
int const sphereSize = 1 * sizeof(int);
// Константа, задающая размер для тетраэдра
int const tetrahedronSize = 1 * sizeof(int);
// Константа, задающая размер для параллелепипеда
int const parallelepipedSize = 3 * sizeof(int);
// Константа, задающая размер для треугольника
int const shapeSize = sizeof(int) + parallelepipedSize;
// Константа, определяющая размерность массива фигур
int const maxSize = 10000 * shapeSize;
// Константа, задающая признак сферы
int const SPHERE = 1;
// Константа, задающая признак тетраэдра
int const TETRAHEDRON = 2;
// Константа, задающая признак параллелепипеда
int const PARALLELEPIPED = 3;

//------------------------------------------------------------------------------
// Описание используемых функций
//------------------------------------------------------------------------------

// Ввод содержимого контейнера из указанного файла
void InContainer(void *c, int *len, FILE *ifst);
// Случайный ввод содержимого контейнера
void InRndContainer(void *c, int *len, int size);
// Вывод содержимого контейнера в файл
void OutContainer(void *c, int len, FILE *ofst);
// Вычисление средней плозади поверхности всех фигур в контейнере
extern double AreaAverageContainer(void *c, int len);
// Удаляет из контейнера фигуры, площадь поверхности которых меньше, чем средняя
// Возворащает количество оставшихся фигур
extern int DeleteLessAverageContainer(void *c, int len);

#endif
