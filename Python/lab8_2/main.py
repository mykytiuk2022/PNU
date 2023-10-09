def improved_bubble_sort(arr):
    swapped = True
    size = len(arr)
    left = 0
    right = size - 1
    last_swap = size - 1

    while left < right and swapped:
        swapped = False
        for i in range(left, right):
            if arr[i] > arr[i + 1]:
                arr[i], arr[i + 1] = arr[i + 1], arr[i]
                swapped = True
                last_swap = i
        right = last_swap
        if not swapped:
            break
        swapped = False
        for j in range(right, left, -1):
            if arr[j] < arr[j - 1]:
                arr[j], arr[j - 1] = arr[j - 1], arr[j]
                swapped = True
                last_swap = j
        left = last_swap


my_list = [64, 34, 25, 12, 22, 11, 90]
improved_bubble_sort(my_list)
print("Відсортований масив:", my_list)
