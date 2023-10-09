def median(arr):
    size = len(arr)
    if size % 2 == 0:
        return arr[size // 2]
    else:
        return arr[size // 2 - 1] + arr[size // 2] / 2


def average(arr):
    return sum(arr) / len(arr)


my_list = [64, 34, 25, 12, 22, 11, 90]
my_list = sorted(my_list)
average_value = average(my_list)
median_value = median(my_list)
print(my_list)
print(f"Середнє значення: {average_value:.2f}, медіана: {median_value:.2f}")
