// Автор: Мамаев Александр (alxmamaev@mail.ru)
// GitHub: https://github.com/alxmamaev/servduino


// Библиотека для работы с сетевой картой
#include <EtherCard.h>

// Буффер сетевой карты
byte Ethernet::buffer[200];

// Адрес сайта на который будем стучаться (в моем случае он запускается на одном с сервером IP)
const char website[] PROGMEM = "192.168.0.100"; //Замените на ip адрес вашего компьютера

// IP адрес сервера.
static byte websiteip[] = { 192,168,0,100 }; //Замените на ip адрес вашего компьютера
static uint32_t timer;

// Действия после успешной отправки данных

//Мак-адрес устройства
static byte mac[] = { 0x74,0x69,0x69,0x2D,0x30,0x31 };

//функция колбэка (нелбходима для обраюотки полученных данных)
static void callback (byte status, word off, word len) {
  Serial.println(">>>");
  Ethernet::buffer[off+300] = 0;
  Serial.print((const char*) Ethernet::buffer + off);
  Serial.println("...");
}

// Функция отправки данных на сервер
void send_package(){
    ether.packetLoop(ether.packetReceive());
    if (millis() > timer) {
    	Serial.println(F("<<PING"));
    	timer = millis() + 5000;
    	ether.browseUrl(PSTR("/cgi-bin/handler.py?"),"cxem=i_love_arduno", website, callback);
  }
}

void setup () {
  Serial.begin(9800);

  if (ether.begin(sizeof Ethernet::buffer, mac) == 0)
    Serial.println(F("Failed to access Ethernet controller"));
  else
    Serial.println(F("Successfully to access Ethernet controller"));
  if (!ether.dhcpSetup())
    Serial.println(F("DHCP failed"));
  else
    Serial.println(F("Successfully DHCP"));

  memcpy(ether.hisip, websiteip, sizeof(websiteip));
  ether.printIp(F("SRV: "), ether.hisip);
}

void loop () {
	//отправляем данные
  send_package();
}
