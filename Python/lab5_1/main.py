num = int(input("Введіть ціле додатнє число: "))
if num != 0 and (num & (num - 1)) == 0:
    print(f"{num} є степенем двійки.")
else:
    print(f"{num} не є степенем двійки.")
