def blackjack(cards):
    card_values = {'2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9,
                   'T': 10, 'J': 10, 'Q': 10, 'K': 10, 'A': 11}

    score = 0
    aces = 0

    for card in cards:
        score += card_values[card]
        if card == 'A':
            aces += 1

    for i in range(aces):
        if score > 21 and aces > 0:
            score -= 10
            aces -= 1

    if score <= 21:
        return score
    else:
        return 'Bust'


input_cards = input("Введіть карти (без пробілів): ")
result = blackjack(input_cards)

print("Результат:", result)
