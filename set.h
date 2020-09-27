
#include <ESP8266WiFi.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step1-wifi
#include <ESP8266WebServer.h>   //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step2-webserver
#include <ESP8266SSDP.h>        //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step3-ssdp
#include <FS.h>                 //Содержится в пакете. Видео с уроком http://esp8266-arduinoide.ru/step4-fswebserver
//                    ПЕРЕДАЧА ДАННЫХ НА WEB СТРАНИЦУ. Видео с уроком http://esp8266-arduinoide.ru/step5-datapages/
//                    ПЕРЕДАЧА ДАННЫХ С WEB СТРАНИЦЫ.  Видео с уроком http://esp8266-arduinoide.ru/step6-datasend/
#include <ArduinoJson.h>        //Установить из менеджера библиотек. https://arduinojson.org/
//                    ЗАПИСЬ И ЧТЕНИЕ ПАРАМЕТРОВ КОНФИГУРАЦИИ В ФАЙЛ. Видео с уроком http://esp8266-arduinoide.ru/step7-fileconfig/
#include <ESP8266HTTPUpdateServer.h>  //Содержится в пакете.  Видео с уроком http://esp8266-arduinoide.ru/step8-timeupdate/
#include <DNSServer.h> //Содержится в пакете.  // Для работы символьных имен в режиме AP отвечает на любой запрос например: 1.ru
#include <TickerScheduler.h>         //https://github.com/Toshik/TickerScheduler Видео с уроком http://esp8266-arduinoide.ru/step8-timeupdate/
#include <WebSocketsServer.h>    //https://github.com/Links2004/arduinoWebSockets 
// Библиотеки устройств
//#include <DHT.h>                     //https://github.com/markruys/arduino-DHT   Support for DHT11 and DHT22/AM2302/RHT03

// Объект для обнавления с web страницы
//ESP8266HTTPUpdateServer httpUpdater;

// Web интерфейс для устройства
ESP8266WebServer HTTP(80);

// Для файловой системы
File fsUploadFile;

// Для работы символьных имен в режиме AP
DNSServer dnsServer;

//Планировщик задач (Число задач)
TickerScheduler ts(2);

// Объект для  webSocket
WebSocketsServer webSocket = WebSocketsServer(81);

#include <Wire.h>
#include <AHT10.h>

AHT10 myAHT10g(AHT10_ADDRESS_0X38);
AHT10 myAHT10s(AHT10_ADDRESS_0X39);

#define relay1pin 12
#define relay2pin 14
// Датчик DHT
//#define dhtPin 4
//DHT dht;
void HTTP_init(void);

boolean r1 = false;
boolean r2 = false;
String r1_Name = "OFF";
String r2_Name = "OFF";
uint8_t s1 = 0;
uint8_t s2 = 0;
String s1_Name = "OFF";
String s2_Name = "OFF";

#include <Servo.h>
Servo servo;


String configSetup = "{}"; // данные для config.setup.json
String configJson = "{}";  // данные для config.live.json
