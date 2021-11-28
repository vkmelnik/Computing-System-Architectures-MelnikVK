# coding=utf-8
import random
import time
import sys

from container import Container


def help():
    print("This program reads and writes different shapes in files, finds area of each shape.")
    print("Shapes can be 3 different kinds - sphere, parallelepiped and tetrahedron.")
    print("Input files include a number of shapes and shapes described like this:")
    print("Sphere: 0 <density> <radius>")
    print("Parallelepiped: 1 <density> <side1> <side2> <side3>")
    print("Tetrahedron: 2 <density> <side>\n")
    print("Use:")
    print("-f <input file> <output file> <output file2> (optional)\n  - read shapes from <input file> and write them "
          "to <output file>.")
    print("-r <number of shapes> <output file> <output file2> (optional)\n  - create some randoms shapes and write "
          "them to <output file>.")
    print("-h\n  - show help (this information).")
    print("If <output file2> is used, the program will write there shapes after deleting all, who has")
    print("area less then average area of all shapes in the initial container.")


# Execute function number 19 and output shapes in the file.
def out_after_function(c, file_name):
    c.delete_less_then_average();
    print("\nShapes, that are left in the container after executing the function.")
    c.output(file_name)
    print("\nShapes, which area is not less then average are written in the file " + file_name)


def is_number_of_shapes(line):
    return line.isdigit() and int(line) > 0


# Main function.
def main(argv):
    argc = len(argv)
    random.seed(time.time())

    try:
        if argv[0] == "-f" and argc >= 3:
            c = Container.input(argv[1])

            c.output(argv[2])
            if argc == 4:
                out_after_function(c, argv[3])
        elif argv[0] == "-r" and argc >= 3:
            if not is_number_of_shapes(argv[1]):
                print("Invalid format of arguments. Use flag -h for help.")
                return
            cnt = int(argv[1])
            c = Container.init_random(cnt)

            c.output(argv[2])
            if argc == 4:
                out_after_function(c, argv[3])
        elif argv[0] == "-h":
            help()
        else:
            print("Invalid format of arguments. Use flag -h for help.")
    except IOError:
        print("File not found")
    except Exception as e:
        print(e.message)


if __name__ == '__main__':
    argv = sys.argv
    main(argv[1:])
