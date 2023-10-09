def blackjack(cards):
    cards_scores = {i: i for i in range(2, 11)}
    cards_scores.update({'T': 10, 'J': 10, 'Q': 10, 'K': 10, 'A': (1, 11)})


