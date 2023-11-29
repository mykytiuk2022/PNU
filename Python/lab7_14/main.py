import re


def valid_email(mail):
    pattern = r'^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-z]{2,}$'
    return re.search(pattern, mail) is not None


email = input("Введіть e-mail: ")
print("E-mail є коректним?")
print(valid_email(email))
