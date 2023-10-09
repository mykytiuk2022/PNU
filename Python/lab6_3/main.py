def deposit(available, final, rate):
    i = 0
    rate = rate / 100
    while available < final:
        available += available * rate
        i += 1
    return i


available_amount = float(input("Введіть початкову суму: "))
final_amount = float(input("Введіть потрібну суму: "))
annual_rate = float(input("Введіть річну процентну ставку: "))
years = deposit(available_amount, final_amount, annual_rate)
print("Необхідна кількість років:", years)
