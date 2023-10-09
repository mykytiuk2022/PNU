import decimal
income = decimal.Decimal(input('Введіть місячний дохід: '))
s = income * (decimal.Decimal(0.015) + decimal.Decimal(0.18))
print('Cуми податків, що необхідно сплатити до бюджету: ', s)
