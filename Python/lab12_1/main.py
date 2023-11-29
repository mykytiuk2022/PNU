import math


class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self, point):
        return math.sqrt((self.x - point.x) ** 2 + (self.y - point.y) ** 2)


class Triangle:
    def __init__(self, point_a, point_b, point_c):
        self.point_a = point_a
        self.point_b = point_b
        self.point_c = point_c

    def is_exist(self):
        ab = self.point_a.distance(self.point_b)
        ac = self.point_a.distance(self.point_c)
        bc = self.point_b.distance(self.point_c)
        return ab + ac > bc and ab + bc > ac and ac + bc > ab

    def perimeter(self):
        ab = self.point_a.distance(self.point_b)
        ac = self.point_a.distance(self.point_c)
        bc = self.point_b.distance(self.point_c)
        return ab + ac + bc

    def area(self):
        ab = self.point_a.distance(self.point_b)
        ac = self.point_a.distance(self.point_c)
        bc = self.point_b.distance(self.point_c)
        p = self.perimeter() / 2
        return math.sqrt(p * (p - ab) * (p - ac) * (p - bc))


point_1 = Point(0, 0)
point_2 = Point(0, 1)
point_3 = Point(1, 0)
triangle = Triangle(point_1, point_2, point_3)
