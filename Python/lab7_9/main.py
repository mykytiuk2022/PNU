def is_lucky(number):
    half_len = len(number) // 2
    sum1 = sum(int(digit) for digit in number[:half_len])
    sum2 = sum(int(digit) for digit in number[-half_len:])
    return sum1 == sum2


ticket = input("Введіть число білета: ")
print(is_lucky(ticket))
