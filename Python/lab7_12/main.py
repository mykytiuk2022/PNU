def delete_spaces(string):
    while "  " in string:
        string = string.replace("  ", " ")
    string = string.strip()
    return string


my_str = input("Введіть рядок:")
print("Рядок без зайвих пробілів:")
print(delete_spaces(my_str))
