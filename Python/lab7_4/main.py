def encryption(string):
    return "".join(chr(ord(char) + 1) for char in string)


my_str = input("Введіть рядок: ")
print("Зашифрований рядок:", encryption(my_str))
