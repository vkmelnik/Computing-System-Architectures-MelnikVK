#include <cstdio>
#include "container.h"
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

// Display help.
void help() {
    printf("This program reads and writes different shapes in files, finds area of each shape.\n");
    printf("Shapes can be 3 different kinds - sphere, parallelepiped and tetrahedron.\n");
    printf("Input files include a number of shapes and shapes described like this:\n");
    printf("Sphere: 0 <density> <radius>\n");
    printf("Parallelepiped: 1 <density> <side1> <side2> <side3>\n");
    printf("Tetrahedron: 2 <density> <side>\n\n");
    printf("Use:\n");
    printf("-f <input file> <output file> <output file2> (optional)\n  - read shapes from <input file> and write them to <output file>.\n");
    printf("-r <output file> <output file2> (optional)\n  - create some randoms shapes and write them to <output file>.\n");
    printf("-h\n  - show help (this information).\n");
    printf("If <output file2> is used, the program will write there shapes after deleting all, who has\n");
    printf("area less then average area of all shapes in the initial container.\n");
}

// Execute function number 19 and output shapes in the file.
void outAfterFunction(container *c, char *fileName) {
    DeleteLessThenAverage(c);
    printf("\nShapes, that are left in the container after executing the function.\n\n");
    FILE *outfile = fopen(fileName, "w+");
    Out(outfile, c);
    fclose(outfile);
    printf("\nShapes, which area is not less then average are written in the file %s\n", fileName);
}

// Main function.
int main(int argc, char* argv[]) {
    container c;
    srand(time(nullptr));

    if(!strcmp(argv[1], "-f") && argc >= 4) {
        FILE *infile = fopen(argv[2], "r+");
        In(infile, &c);
        fclose(infile);

        FILE *outfile = fopen(argv[3], "w+");
        Out(outfile, &c);
        fclose(outfile);
        if (argc == 5)
            outAfterFunction(&c, argv[4]);
    } else if (!strcmp(argv[1], "-r") && argc >= 3) {
        InitRandom(&c);

        FILE *outfile = fopen(argv[2], "w+");
        Out(outfile, &c);
        fclose(outfile);
        if (argc == 4)
            outAfterFunction(&c, argv[3]);
    } else if (!strcmp(argv[1], "-h")) {
        help();
    } else {
        printf("Invalid format of arguments. Use flag -h for help.\n");
    }
    return 0;
}
