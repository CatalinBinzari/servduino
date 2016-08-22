!/usr/bin/env python3
import cgi # Импортируем библиотеку для работы с get запросами
  		  
print(Hello CXEM.NET!)		 
values = cgi.FieldStorage() # получаем все переданные данные в виде словаря
one = int(values.getfirst("one", 0)) #получаем необходимое нам значение
two = int(values.getfirst("two", 0)) #получаем необходимое нам значение
print(one + two)
