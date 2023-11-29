import socket
import datetime
import locale

locale.setlocale(locale.LC_ALL, 'uk_UA.UTF-8')

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = '127.0.0.1'
port = 9999
server_socket.bind((host, port))
server_socket.listen(1)
print("Сервер чекає на з'єднання...")

while True:
    client_socket, addr = server_socket.accept()
    print("Отримано зв'язок з {}".format(addr))

    client_socket.send('Вітаю! Як тебе звати?'.encode('utf-8'))
    client_name = client_socket.recv(1024).decode('utf-8')
    print("Ім'я клієнта:", client_name)

    client_socket.send('Привіт, {}. Що б ти хотів дізнатись?'.format(client_name).encode('utf-8'))
    while True:
        try:
            client_question = client_socket.recv(1024).decode('utf-8')

            if 'як твоє ім\'я' in client_question.lower():
                server_response = "Можеш звати мене Сервер."
            elif 'який зараз день' in client_question.lower():
                current_day = datetime.datetime.now().strftime("%A")
                server_response = "Сьогодні {}".format(current_day)
            elif 'яка година' in client_question.lower():
                current_time = datetime.datetime.now().strftime("%H:%M")
                server_response = "Поточний час {}".format(current_time)
            elif 'вийти' in client_question.lower() or 'бувай' in client_question.lower():
                break
            else:
                server_response = "Вибачте, я не зрозумів вашого запитання."
            client_socket.send(server_response.encode('utf-8'))
        except (ConnectionResetError, ConnectionAbortedError):
            print("З'єднання з {} втрачено".format(addr))
            break
    client_socket.close()
