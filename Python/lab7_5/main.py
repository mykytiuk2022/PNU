vowels = "aAoOuUiIeEyY"
text = input("Введіть текст: ")
i = 0
for char in text:
    if char in vowels:
        i += 1
print("Кількість голосних літер у тексті:", i)
