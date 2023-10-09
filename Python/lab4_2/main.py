import math
x = float(input('Введіть 1 число: '))
u = float(input('Введіть 2 число: '))
o = float(input('Введіть 3 число: '))
factor1 = 1/(o*math.sqrt(2*math.pi))
divided = (x-u) ** 2
division = 2 * (o ** 2)
factor2 = math.exp(-(divided/division))
result = factor1*factor2
print('Результат: ', result)
