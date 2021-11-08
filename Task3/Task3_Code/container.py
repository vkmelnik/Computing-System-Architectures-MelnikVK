from shape import Shape


# Container of shapes.
class Container:

    max_length = 10000

    def __init__(self):
        self.shapes = []
        self.number_of_shapes = 0

    @staticmethod
    def init_random(cnt):
        if cnt > Container.max_length:
            print("Too much shapes were requested. The program will generate only", Container.max_length)
            cnt = Container.max_length
        container = Container()
        container.number_of_shapes = cnt
        for i in range(cnt):
            container.shapes.append(Shape.init_random())
        return container

    def output(self, file_name):
        with open(file_name, "w") as f:
            print("Number of shapes: " + str(self.number_of_shapes))
            f.write("Number of shapes: " + str(self.number_of_shapes) + "\n")
            for i in range(len(self.shapes)):
                self.shapes[i].output(f)

    @staticmethod
    def input(file_name):
        with open(file_name, "r") as f:
            cnt = f.readline()[:-1]
            if (not cnt.isdigit()) or (int(cnt) < 0 or int(cnt) > Container.max_length):
                print("Reading error: expected number of shape.")
                return
            container = Container()
            container.number_of_shapes = int(cnt)
            for i in range(container.number_of_shapes):
                args = map(int, f.readline().split())
                container.shapes.append(Shape.input(args))
            return container

    # Delete shapes, whose area is less then average.
    def delete_less_then_average(self):
        if self.number_of_shapes <= 0:
            return
        average_area = sum(s.find_area() for s in self.shapes) / self.number_of_shapes
        new_shapes = []
        for i in range(self.number_of_shapes):
            if self.shapes[i].find_area() >= average_area:
                new_shapes.append(self.shapes[i])
        self.shapes = new_shapes
        self.number_of_shapes = len(self.shapes)
