h1, m1 = map(int, input("Введіть початок проміжку часу першого свідка h1:m1: ").split())
h2, m2 = map(int, input("Введіть кінець проміжку часу першого свідка h2:m2: ").split())
h3, m3 = map(int, input("Введіть початок проміжку часу другого свідка h3:m3: ").split())
h4, m4 = map(int, input("Введіть кінець проміжку часу другого свідка h4:m4: ").split())
first_start = h1 * 60 + m1
first_end = h2 * 60 + m1
second_start = h3 * 60 + m3
second_end = h4 * 60 + m4
if first_start < second_end and second_start < first_end:
    print("Обоє свiдка можуть одночасно говорити правду")
else:
    print("Обоє свiдка не можуть одночасно говорити правду")
