def integer_to_roman(number):
    roman_numerals = {
        1000: 'M',
        900: 'CM',
        500: 'D',
        400: 'CD',
        100: 'C',
        90: 'XC',
        50: 'L',
        40: 'XL',
        10: 'X',
        9: 'IX',
        5: 'V',
        4: 'IV',
        1: 'I'
    }

    roman_number = ""
    for value, numeral in roman_numerals.items():
        while number >= value:
            roman_number += numeral
            number -= value

    return roman_number


def roman_to_integer(roman_number):
    roman_numerals = {
        'M': 1000,
        'D': 500,
        'C': 100,
        'L': 50,
        'X': 10,
        'V': 5,
        'I': 1
    }

    integer_number = 0
    prev_value = 0

    for numeral in roman_number:
        value = roman_numerals[numeral]

        if prev_value < value:
            integer_number += value - 2 * prev_value
        else:
            integer_number += value

        prev_value = value

    return integer_number


print("Виберіть дію:")
print("1. Конвертувати арабське число в римське")
print("2. Конвертувати римське число в арабське")
choice = input("Ваш вибір: ")

if choice == '1':
    num = int(input("Введіть арабське число: "))
    print(integer_to_roman(num))
elif choice == '2':
    num = input("Введіть римське число: ")
    print(roman_to_integer(num))
else:
    print("Непривильний вибір")
