import random


# Створення ігрового поля
def create_board():
    board = []
    for i in range(3):
        row = []
        for j in range(3):
            row.append("-")
        board.append(row)
    return board


# Функція для друку ігрового поля
def print_board(board):
    for row in board:
        for cell in row:
            print(cell, end=" ")
        print()


# Функція для перевірки перемоги
def check_win(board, player):
    # Перевірка рядків
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] == player:
            return True

    # Перевірка стовпчиків
    for j in range(3):
        if board[0][j] == board[1][j] == board[2][j] == player:
            return True

    # Перевірка діагоналей
    if board[0][0] == board[1][1] == board[2][2] == player:
        return True
    if board[0][2] == board[1][1] == board[2][0] == player:
        return True

    return False


# Функція для ходу комп'ютера
def make_computer_move(board, user, computer):
    # Перевірка, чи може комп'ютер перемогти в наступному ході
    for i in range(3):
        for j in range(3):
            if board[i][j] == "-":
                board[i][j] = computer
                if check_win(board, computer):
                    return
                # Відміна ходу
                board[i][j] = "-"

    # Перевірка, чи може користувач перемогти в наступному ході
    for i in range(3):
        for j in range(3):
            if board[i][j] == "-":
                board[i][j] = user
                if check_win(board, user):
                    board[i][j] = computer
                    return

                # Відміна ходу
                board[i][j] = "-"

    # Хід в будь-яку вільну клітинку
    while True:
        i = random.randint(0, 2)
        j = random.randint(0, 2)
        if board[i][j] == "-":
            board[i][j] = computer
            return


# Функція початку гри
def play_game(user="x"):
    # Ініціалізація ігрового поля
    board = create_board()
    computer = 'o' if user == 'x' else 'x'
    # Визначення хто ходить першим
    current_player = "x"

    # Основний цикл гри
    while True:
        print_board(board)
        # Перевірка чий хід
        if current_player == user:
            print("Ваш хід")
            # Хід користувача
            while True:
                try:
                    row = int(input("Введіть рядок (1-3) "))
                    col = int(input("Введіть стовпчик (1-3) "))
                    row -= 1
                    col -= 1

                    if 0 <= row <= 2 and 0 <= col <= 2 and board[row][col] == "-":
                        board[row][col] = user
                        break
                    else:
                        print("Неправильний хід. Спробуйте ще раз.")
                except ValueError:
                    print("Неправильний ввід. Спробуйте ще раз.")
        else:
            print("Хід комп'ютера")
            # Хід комп'ютера
            make_computer_move(board, user, computer)
        # Перевірка перемоги користувача або комп'ютера
        if check_win(board, current_player):
            print_board(board)
            if current_player == user:
                print("Ви перемогли!")
            else:
                print("Комп'ютер переміг!")
            break
        # Перевірка на нічию
        if all(board[i][j] != "-" for i in range(3) for j in range(3)):
            print_board(board)
            print("Нічия!")
            break
        # Зміна ходу
        current_player = computer if current_player == user else user


while True:
    user_side = input("Виберіть вашу сторону ('x' або 'o'): ").lower()
    if user_side == 'x' or user_side == 'o':
        break
    else:
        print("Неправильний ввід. Спробуйте ще раз.")
play_game(user_side)
