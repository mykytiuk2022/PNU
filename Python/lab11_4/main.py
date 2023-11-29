from datetime import datetime

m1, d1, w1 = map(int, input("Введіть m1, d1 та w1 - мiсяць, число i день тижня першої дати").split())
m2, d2 = map(int, input("Введіть m2 та d2 - мiсяць i число другої дати").split())

date1 = datetime(2023, m1, d1)
date2 = datetime(2023, m2, d2)

date_difference = date2 - date1
print(date_difference)
w2 = date_difference.days % 7
print(w2)
