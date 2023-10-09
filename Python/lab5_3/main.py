import random

variant = ["Камінь", "Ножиці", "Папір"]
choice = input("Введіть свій вибір (Камінь, Ножиці, Папір): ")

if choice in variant:
    randomChoice = random.choice(variant)
    print("Комп'ютер вибрав:", randomChoice)
    if choice == randomChoice:
        print("Нічия")
    elif ((choice == "Камінь" and randomChoice == "Ножиці")
          or (choice == "Ножиці" and randomChoice == "Папір")
          or choice == "Папір" and randomChoice == "Камінь"):
        print("Вітаю, ви перемогли")
    else:
        print("На жаль, ви програли")
else:
    print("Невірний ввід")
