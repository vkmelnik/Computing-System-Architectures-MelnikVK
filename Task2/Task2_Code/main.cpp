#include <cstdio>
#include "Container.h"
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
    printf("-r <number of shapes> <output file> <output file2> (optional)\n  - create some randoms shapes and write them to <output file>.\n");
    printf("-h\n  - show help (this information).\n");
    printf("If <output file2> is used, the program will write there shapes after deleting all, who has\n");
    printf("area less then average area of all shapes in the initial container.\n");
}

// Execute function number 19 and output shapes in the file.
void outAfterFunction(Container *c, char *fileName) {
    c->DeleteLessThenAverage();
    printf("\nShapes, that are left in the container after executing the function.\n");
    FILE *outfile = fopen(fileName, "w+");
    c->Out(outfile);
    fclose(outfile);
    printf("\nShapes, which area is not less then average are written in the file %s\n", fileName);
}

bool isNumberOfShapes(char* line)
{
    char* p;
    int x = strtol(line, &p, 10);
    return ((*p == 0) && (x > 0));
}

// Main function.
int main(int argc, char* argv[]) {
    Container* c;
    srand(time(nullptr));

    if(!strcmp(argv[1], "-f") && argc >= 4) {
        FILE *infile = fopen(argv[2], "r+");
        c = Container::In(infile);
        fclose(infile);

        FILE *outfile = fopen(argv[3], "w+");
        c->Out(outfile);
        fclose(outfile);
        if (argc == 5)
            outAfterFunction(c, argv[4]);
    } else if (!strcmp(argv[1], "-r") && argc >= 4) {
        if (!isNumberOfShapes(argv[2])) {
            printf("Invalid format of arguments. Use flag -h for help.\n");
            return 0;
        }
        int cnt = atoi(argv[2]);
        c = Container::InitRandom(cnt);

        FILE *outfile = fopen(argv[3], "w+");
        c->Out(outfile);
        fclose(outfile);
        if (argc == 5)
            outAfterFunction(c, argv[4]);
    } else if (!strcmp(argv[1], "-h")) {
        help();
    } else {
        printf("Invalid format of arguments. Use flag -h for help.\n");
    }
    return 0;
}
