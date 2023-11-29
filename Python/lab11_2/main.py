def random_number_generator(x):
    while True:
        x = str(x).zfill(6)
        y = x[3:] + x[:3]
        result = str(int(x) * int(y)).zfill(12)
        random_number = int(result[3:9])
        yield random_number
        x = random_number


seed = int(input("Введіть початкове значення: "))
random_numbers = random_number_generator(seed)
for i in range(15):
    print(next(random_numbers))
