def number_to_word(number):
    digits = {
        0: '',
        1: 'одна',
        2: 'дві',
        3: 'три',
        4: 'чотири',
        5: 'п\'ять',
        6: 'шість',
        7: 'сім',
        8: 'вісім',
        9: 'дев\'ять'
    }
    teens = {
        10: 'десять',
        11: 'одинадцять',
        12: 'дванадцять',
        13: 'тринадцять',
        14: 'чотирнадцять',
        15: 'п\'ятнадцять',
        16: 'шістнадцять',
        17: 'сімнадцять',
        18: 'вісімнадцять',
        19: 'дев\'ятнадцять'
    }
    tens = {
        2: 'двадцять',
        3: 'тридцять',
        4: 'сорок',
        5: 'п\'ятдесят',
        6: 'шістдесят',
        7: 'сімдесят',
        8: 'вісімдесят',
        9: 'дев\'яносто'
    }
    hundreds = {
        1: 'сто',
        2: 'двісті',
        3: 'триста',
        4: 'чотириста',
        5: 'п\'ятсот',
        6: 'шістсот',
        7: 'сімсот',
        8: 'вісімсот',
        9: 'дев\'ятсот'
    }
    result = ""
    if number < 10:
        result = digits[number]
        return result
    elif number < 20:
        return teens[number]
    elif number < 100:
        result += tens[number // 10]
        if number % 10 != 0:
            result += " " + number_to_word(number % 10)
        return result
    elif number < 1000:
        result += hundreds[number // 100] + " " + number_to_word(number % 100)
        return result
    elif number < 1000000:
        result += number_to_word(number // 1000) + thousand_case(number // 1000) + number_to_word(number % 1000)
        return result


def hryvnia_case(number):
    last_digit = number % 10
    if last_digit == 1:
        return " гривня "
    elif 1 < last_digit < 5:
        return " гривні "
    else:
        return " гривень "


def kopecks_case(number):
    last_digit = number % 10
    if last_digit == 1:
        return " копійка"
    elif 1 < last_digit < 5:
        return " копійки"
    else:
        return " копійок"


def thousand_case(number):
    last_digit = number % 10
    if last_digit == 1:
        return " тисяча "
    elif 1 < last_digit < 5:
        return " тисячі "
    else:
        return " тисяч "


num = float(input("Введіть число (формат: 123456.78)"))
ints = int(num)
kopecks = round((num - ints) * 100)
words = number_to_word(ints) + hryvnia_case(ints)
if kopecks != 0:
    words += number_to_word(kopecks) + kopecks_case(kopecks)
print("Представлення грошової суми прописом:")
print(words)
