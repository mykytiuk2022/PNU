def replace_elements(string, k):
    if abs(k) > len(string) // 2:
        return "Помилка. k більше половини довжини рядка"
    print(k)
    res = string[k:] + string[:k]
    return res


my_str = input("Введіть рядок тексту: ")
k = int(input("Введіть позицію зсуву: "))
print(replace_elements(my_str, k))
