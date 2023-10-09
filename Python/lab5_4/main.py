import math
print("Квадратне рівняння a * x^2 + b * x + c = 0 ")
a = float(input("Введіть коефіцієнт a: "))
b = float(input("Введіть коефіцієнт b: "))
c = float(input("Введіть коефіцієнт c: "))
discriminator = b**2 - 4*a*c
if discriminator < 0:
    print("Рівняння не має коренів")
elif discriminator == 0:
    root = -b / (2*a)
    print("Корінь квадратного рівняння:", root)
else:
    root1 = (-b - math.sqrt(discriminator)) / (2*a)
    root2 = (-b + math.sqrt(discriminator)) / (2*a)
    print("Корені квадратного рівняння:", root1, root2)