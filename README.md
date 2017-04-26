# servduino
Данный проект предназначен, что-бы продемонстрировать возможности arduino при работе с сервером. <br>
[Статья](http://cxem.net/arduino/arduino197.php) с подробным описанием проекта.

## Структура
* */server* - папка с сервером, который будет запущен на вашем ПК
  * *run.py* - файл запуска сервера
  * */cgi-bin* - папка с скриптами-обработчиками http-запросов
    * *handler.py* - пример обработчика http-запросов от ардуино
* */arduino* - папка с скетчами для ардуино

## Зависимости
* [Python 3.x](https://www.python.org/downloads/) (для сервера)
* [Ethercard](https://github.com/jcw/ethercard) (библиотека для Arduino)

## Автор
**Мамаев Александр** ([alxmamaev](https://alxmamaev.github.io/))
<br>[Вконтакте](https://vk.com/alxmamaev)
<br>[Телеграм](https://t.me/alxmamaev)
<br>alxmamaev@ya.ru 
