a = float(input("Введіть сторону a: "))
b = float(input("Введіть сторону b: "))
c = float(input("Введіть сторону c: "))

if a + b < c or a + c < b or b + c < a:
    print("Трикутник не існує")
else:
    print("Трикутник існує")
