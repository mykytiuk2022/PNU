def is_palindrome(string):
    cleaned_str = "".join(char.lower() for char in string if char.isalnum())
    return cleaned_str == cleaned_str[::-1]


my_str = input("Введіть рядок тексту: ")
print(is_palindrome(my_str))
