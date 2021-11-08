import math
import random


# Abstract shape.
class Shape:

    def __init__(self):
        # Density of the shape.
        self.density = 0

    # Find surface's area.
    def find_area(self):
        return 0

    # Initialize shape with random values.
    @staticmethod
    def init_random():
        type_key = random.randint(0, 2)
        if type_key == 0:
            return Sphere.init_random()
        elif type_key == 1:
            return Tetrahedron.init_random()
        else:
            return Parallelepiped.init_random()

    # Input sphere from file.
    @staticmethod
    def input(args):
        if len(args) < 2:
            raise Exception("Shapes reading error: not enough parameters to create a shape.")
        shape_type = args[0]
        if args[1] > 0:
            density = args[1]
        else:
            raise Exception("Shapes reading error: density should be a number and more than 0.")
        if shape_type == 0:
            shape = Sphere.input(args[2:])
        elif shape_type == 2:
            shape = Tetrahedron.input(args[2:])
        else:
            shape = Parallelepiped.input(args[2:])
        shape.density = density
        return shape

    # Output sphere from file.
    def output(self, f):
        raise NotImplementedError("Abstract shape cannot be output.")


# Sphere.
class Sphere(Shape):

    def __init__(self, radius):
        # Radius of the sphere.
        Shape.__init__(self)
        self.radius = radius

    # Find surface's area.
    def find_area(self):
        pi = 3.14159265359
        return 4 * pi * self.radius * self.radius

    # Initialize sphere with random values.
    @staticmethod
    def init_random():
        return Sphere(random.uniform(0, 100.0))

    # Input sphere from file.
    @staticmethod
    def input(args):
        if len(args) > 0 and args[0] > 0:
            return Sphere(args[0])
        else:
            raise Exception("Sphere reading error: radius not specified.")

    # Output sphere from file.
    def output(self, f):
        message = "Sphere with radius " + str(self.radius) + ", area " + str(self.find_area())\
                  + " and density " + str(self.density)
        f.write(message + "\n")
        print(message)


# Tetrahedron.
class Tetrahedron(Shape):

    def __init__(self, side):
        # Side of the tetrahedron.
        Shape.__init__(self)
        self.side = side

    # Find surface's area.
    def find_area(self):
        return math.sqrt(3) * self.side * self.side

    # Initialize tetrahedron with random values.
    @staticmethod
    def init_random():
        return Tetrahedron(random.randrange(1000))

    # Input tetrahedron from file.
    @staticmethod
    def input(args):
        if len(args) > 0 and args[0] > 0:
            return Tetrahedron(args[0])
        else:
            raise Exception("Tetrahedron reading error: side not specified.")

    # Output tetrahedron from file.
    def output(self, f):
        message = "Tetrahedron with side " + str(self.side) + ", area " + str(self.find_area()) \
                  + " and density " + str(self.density)
        f.write(message + "\n")
        print(message)


# Parallelepiped.
class Parallelepiped(Shape):

    def __init__(self, side1, side2, side3):
        # Sides of the parallelepiped.
        Shape.__init__(self)
        self.side1 = side1
        self.side2 = side2
        self.side3 = side3

    # Find surface's area.
    def find_area(self):
        return (self.side1 * self.side2 + self.side1 * self.side3 + self.side2 * self.side3) * 2

    # Initialize parallelepiped with random values.
    @staticmethod
    def init_random():
        return Parallelepiped(random.randrange(1000), random.randrange(1000), random.randrange(1000))

    # Input parallelepiped from file.
    @staticmethod
    def input(args):
        if len(args) >= 3 and args[0] > 0 \
                and args[1] > 0 \
                and args[2] > 0:
            return Parallelepiped(args[0], args[1], args[2])
        else:
            raise Exception("Parallelepiped reading error: one or more sides are not specified.")

    # Output parallelepiped from file.
    def output(self, f):
        message = "Parallelepiped with sides " + str(self.side1) + " " + str(self.side2) + " "\
                  + str(self.side3) + ", area " + str(self.find_area()) + " and density " + str(self.density)
        f.write(message + "\n")
        print(message)
