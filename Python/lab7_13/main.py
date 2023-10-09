def is_possible(s1, s2):
    s1 = s1.lower()
    s2 = s2.lower()
    for char in s2:
        if char not in s1:
            return False
    return True


my_str1 = input("Введіть перший рядок: ")
my_str2 = input("Введіть другий рядок: ")
print("Чи можна з деяких символів першого рядка утворити другий рядок?")
print(is_possible(my_str1, my_str2))
