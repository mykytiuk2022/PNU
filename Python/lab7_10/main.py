def min_len(string):
    words = string.split()
    min_word = min(len(word) for word in words)
    return min_word


my_str = input("Введіть рядок: ")
print("Довжина найкоротшого слова в рядку:", min_len(my_str))
