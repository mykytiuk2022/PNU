import math


def triangle_area(a, b, c):
    p = a + b + c
    s = math.sqrt(p * (p - a) * (p - b) * (p - c))
    return s


a = float(input("Введіть довжину першої сторони: "))
b = float(input("Введіть довжину другої сторони: "))
c = float(input("Введіть довжину третьої сторони: "))
print("Площа трикутника:", triangle_area(a, b, c))
