def calculate_size_generator(file_name, block_size=4096):
    with open(file_name, 'rb') as file:
        while True:
            data_block = file.read(block_size)
            if not data_block:
                break
            yield len(data_block)


log_file = '2017_05_07_nginx.txt'
total_size = sum(calculate_size_generator(log_file))
print(f"Сумарний розмір файлу: {total_size} байт")
