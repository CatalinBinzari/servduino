#!/usr/bin/env python3
import cgi # Импортируем библиотеку для работы с get запросами

values = cgi.FieldStorage() # получаем все переданные данные в виде словаря
cxem = values.getfirst("cxem", "none") #получаем необходимое нам значение
output_file = open("out.txt","a")
output_file.write(cxem) #записываем значение в файл
output_file.close()
