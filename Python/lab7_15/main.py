import random


def password_generator(size):
    size -= 4
    special_characters = "!#$%&*+-=?@^_"
    digits = "0123456789"
    characters_lower = "abcdefghijklmnopqrstuvwxyz"
    characters_upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    all_symbols = special_characters + digits + characters_upper + characters_lower
    password = ""
    password += random.choice(special_characters)
    password += random.choice(characters_upper)
    password += random.choice(characters_lower)
    password += random.choice(digits)
    for i in range(size):
        password += random.choice(all_symbols)
    return password


password_size = int(input("Введіть кількість символів паролю: "))
random_password = password_generator(password_size)
print("Згенерований пароль:", random_password)
