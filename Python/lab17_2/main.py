import timeit
import math

exponent = 8
list_of_strings = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqr', 'stu', 'vwx', 'yz']


def bitwise_shift_power():
    return 2 << exponent


def exponentiation_operator():
    return 2 ** exponent


def pow_function():
    return pow(2, exponent)


def math_pow_function():
    return math.pow(2, exponent)


def reverse_by_map():
    return list(map(lambda x: x[::-1], list_of_strings))


def reverse_by_list_comprehension():
    return [x[::-1] for x in list_of_strings]


def reverse_by_for_loop():
    reversed_list = []
    for x in list_of_strings:
        reversed_list.append(x[::-1])
    return reversed_list


print("Bitwise shift time", timeit.timeit(math_pow_function, number=1))
print("Exponentiation operator time", timeit.timeit(exponentiation_operator, number=1))
print("Pow function time", timeit.timeit(pow_function, number=1))
print("Math pow function time", timeit.timeit(math_pow_function, number=1))
print("Reverse by map time", timeit.timeit(reverse_by_map, number=1))
print("Reverse by list comprehension time", timeit.timeit(reverse_by_list_comprehension, number=1))
print("Reverse by for loop time", timeit.timeit(reverse_by_for_loop, number=1))
