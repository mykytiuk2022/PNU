def is_prime(n):
    if n == 0 or n == 1:
        return False
    i = 2
    while n % i:
        i += 1
    if i == n:
        return True
    else:
        return False


print(is_prime(10))
