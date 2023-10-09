import math
a = float(input('Введіть 1 число:'))
b = float(input('Введіть 2 число:'))
result = (math.sqrt(a*b) / (math.exp(a) * b)) + (a * math.exp(2*a/b))
print('Результат: ', result)
