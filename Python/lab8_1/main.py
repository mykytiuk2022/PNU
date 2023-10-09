def last_person(n, k):
    people = [i for i in range(1, n + 1)]
    while len(people) > 1:
        for i in range(0, k - 1):
            people.append(people[i])
        del people[:k]
    return people[0]


N, K = int(input("Введіть N:")), int(input("Введіть K:"))
last = last_person(N, K)
print("Людина, що залишилася останньою, під номером:", last)
