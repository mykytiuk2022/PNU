morse_code = {
    'a': '.-',
    'b': '-...',
    'c': '-.-.',
    'd': '-..',
    'e': '.',
    'f': '..-.',
    'g': '--.',
    'h': '....',
    'i': '..',
    'j': '.---',
    'k': '-.-',
    'l': '.-..',
    'm': '--',
    'n': '-.',
    'o': '---',
    'p': '.--.',
    'q': '--.-',
    'r': '.-.',
    's': '...',
    't': '-',
    'u': '..-',
    'v': '...-',
    'w': '.--',
    'x': '-..-',
    'y': '-.--',
    'z': '--..'
}


def convert_to_morse(string):
    string = string.lower()
    result = ""
    for char in string:
        if char in morse_code:
            result += morse_code[char]
        else:
            result += " "
    return result


my_str = input("Введіть текст: ")
print("Ваш текст азбукою Морзе:")
print(convert_to_morse(my_str))
