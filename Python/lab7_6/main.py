def asterisk_frame(string):
    border_size = len(string) + 4
    print("*" * border_size)
    print("*", string, "*")
    print("*" * border_size)


my_str = input("Введіть рядок: ")
asterisk_frame(my_str)
