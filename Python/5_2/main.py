h = float(input("Enter the height of the door: "))
w = float(input("Enter the width of the door: "))
a = float(input("Enter the dimension 'a' of the box: "))
b = float(input("Enter the dimension 'b' of the box: "))
c = float(input("Enter the dimension 'c' of the box: "))
if ((a <= h and b <= w) or (a <= w and b <= h) or (a <= h and c <= w)
        or (a <= w and c <= h) or (b <= h and c <= w) or (b <= w and c <= h)):
    print("The box can fit through the door.")
else:
    print("The box cannot fit through the door.")
