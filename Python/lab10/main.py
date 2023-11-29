from os.path import exists


def encode(message, file_name):
    if not file_name.lower().endswith('.bmp'):
        print("Error: Please select a BMP file.")
        return

    if not exists(file_name):
        print(f"Error: File '{file_name}' not found.")
        return

    with open(file_name, "rb") as bmp_file:
        data = bmp_file.read()
    offset = data[10]

    data = bytearray(data)

    data[offset] = len(message)

    for i in range(len(message)):
        data[offset + i + 1] = ord(message[i])

    with open("output_image.bmp", "wb") as file:
        file.write(data)


def decode(file_name):
    if not file_name.lower().endswith('.bmp'):
        print("Error: Please select a BMP file.")
        return

    if not exists(file_name):
        print(f"Error: File '{file_name}' not found.")
        return

    with open(file_name, "rb") as file:
        data = file.read()
        offset = data[10]

        msg_size = data[offset]

        data = bytearray(data)

        message = ""

        for i in range(msg_size):
            message += chr(data[offset + i + 1])

        print(message)


file_name = input("Input the file name\n>> ")
message = input("Input the message\n>> ")
encode(message, file_name)
decode("output_image.bmp")
