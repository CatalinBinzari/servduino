from http.server import HTTPServer, CGIHTTPRequestHandler # Импортируем библиоетеку для запуска Веб-Сервера
import socket # Импортируем библиотеку для работы с веб сокетами (необходимо, что бы узнать ip адресс нашего компьютера)

#данная функция возвращает нам списоcок, в котором второй элемент - наш ip адрес
#Но если отсутствует подключения к сети - возвращает списко длинною в один элемент
if len(socket.gethostbyname_ex(socket.gethostname())[2]) > 1:
    print("Сервер запущен на адресе: %s"%socket.gethostbyname_ex(socket.gethostname())[2][1]) #Выводим полученый ip адрес
server_address = ("", 80) #Устанавливаем адрес сервера и порт.  Порт обязательно 80, так как ардуино стучется по нему.
httpd = HTTPServer(server_address, CGIHTTPRequestHandler) #создаем экземпляр класса (сервер) с нужными настройками
httpd.serve_forever() #запускаем сервер
