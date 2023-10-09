def sort_len(string):
    words = my_str.split()
    sort_word = sorted(words, key=len)
    return " ".join(sort_word)


my_str = input("Введіть текст: ")
print("Відсортувати слова в рядку за збільшенням їх довжини:")
print(sort_len(my_str))

