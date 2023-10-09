def brackets_correct(string):
    stack = []
    for char in string:
        if char == '(' or char == '[' or char == '{' or char == '<':
            stack.append(char)
        elif ((char == ')' and stack[-1] == '(')
              or (char == ']' and stack[-1] == '[')
              or (char == '}' and stack[-1] == '{')
              or (char == '>' and stack[-1] == '<')):
            stack.pop()
    return not stack


brackets = input("Введіть послідовність з дужками: ")
print(brackets_correct(brackets))
