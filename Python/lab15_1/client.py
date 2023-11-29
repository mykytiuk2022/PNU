import socket

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
host = '127.0.0.1'
port = 9999
s.connect((host, port))

server_response = s.recv(1024)
print(server_response.decode('utf-8'))

while True:
    a = input()
    s.send(a.encode('utf-8'))

    server_response = s.recv(1024)
    print(server_response.decode('utf-8'))

    if a.lower() == 'вийти' or a.lower() == 'бувай':
        break

s.close()
