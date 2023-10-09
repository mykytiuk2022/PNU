def deposit(available, rate, years):
    result = available * (1 + rate / 100 / 12) ** (12 * years)
    return result


available_amount = float(input("Введіть початкову суму: "))
annual_rate = float(input("Введіть річну процентну ставку: "))
duration_years = int(input("Введіть тривалість депозиту у роках: "))
final_amount = deposit(available_amount, annual_rate, duration_years)
print("Сума на момент завершення депозиту:", final_amount)
