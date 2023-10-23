import re


def to_camel_case(variable):
    regex = re.compile(r'_[a-z]')
    match = regex.findall(variable)
    for m in match:
        variable = variable.replace(m, m[1].upper())
    return variable


def to_snake_case(variable):
    regex = re.compile(r'[A-Z]')
    match = regex.findall(variable)
    for m in match:
        variable = variable.replace(m, '_' + m.lower())
    return variable


choice = input("Виберіть функцію (1 - toCamelCase, 2 - toSnakeCase): ")

if choice == '1':
    snake_case_variable = input("Введіть змінну для перетворення: ")
    result = to_camel_case(snake_case_variable)
    print("Результат:", result)
elif choice == '2':
    camel_case_variable = input("Введіть змінну для перетворення: ")
    result = to_snake_case(camel_case_variable)
    print("Результат:", result)
else:
    print("Невірний вибір")
