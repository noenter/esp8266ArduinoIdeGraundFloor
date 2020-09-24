void AHT_init(){
  
  uint8_t test1 = 0;
  //uint8_t readStatusg = myAHT10g.readRawData(); //read 6 bytes from AHT10 over I2C
  //uint8_t readStatuss = myAHT10s.readRawData(); //read 6 bytes from AHT10 over I2C
  //delay(1000);
  //jsonWrite(configJson, "ahttime", 2000);
  jsonWrite(configJson, "temperature_g", test1);   // отправить температуру в configJson
  jsonWrite(configJson, "humidity_g", test1);         // отправить влажность в configJson 
  jsonWrite(configJson, "temperature_s", test1);   // отправить температуру в configJson
  jsonWrite(configJson, "humidity_s", test1);         // отправить влажность в configJson     
   
 jsonWrite(configJson, "temperature_g", myAHT10g.readTemperature());   // отправить температуру в configJson
 jsonWrite(configJson, "humidity_g", myAHT10g.readHumidity());   // отправить влажность в configJson 
 jsonWrite(configJson, "temperature_s", myAHT10s.readTemperature());   // отправить температуру в configJson
 jsonWrite(configJson, "humidity_s", myAHT10s.readHumidity()); 
   
  
  ts.add(0, 10000, [&](void*) { // Запустим задачу 2 с интервалом test
      String temperature_g = (String)myAHT10g.readTemperature();
      String humidity_g = (String)myAHT10g.readHumidity();
      String temperature_s = (String)myAHT10s.readTemperature();
      String humidity_s = (String)myAHT10s.readHumidity();     
      SoketData ("temperature_g", temperature_g, jsonRead(configJson,"temperature_g"));
      SoketData ("humidity_g", humidity_g, jsonRead(configJson,"humidity_g"));
      SoketData ("temperature_s", temperature_s, jsonRead(configJson,"temperature_s"));
      SoketData ("humidity_s", humidity_s, jsonRead(configJson,"humidity_s"));
     jsonWrite(configJson, "temperature_g", temperature_g);   // отправить температуру в configJson
      jsonWrite(configJson, "humidity_g", humidity_g);         // отправить влажность в configJson 
      jsonWrite(configJson, "temperature_s", temperature_s);   // отправить температуру в configJson
      jsonWrite(configJson, "humidity_s", humidity_s);         // отправить влажность в configJson     
    Serial.println("Tasks AHT completed");
    }, nullptr, true);
}

// -----------------  Вывод времени и даты в /config.live.json каждую секунду
void sec_init() {
  ts.add(1, 1000, [&](void*) { // Запустим задачу 1 с интервалом 1000ms
    // поместим данные для web страницы в json строку configJson
    // Будем вызывать эту функцию каждый раз при запросе /config.live.json
    // jsonWrite(строка, "ключ", значение_число); Так можно дабавить или обнавить json значение ключа в строке
    // jsonWrite(строка, "ключ", "значение_текст");
    String timeS = GetTime();
    String date = GetDate();
    SoketData ("time", timeS, jsonRead(configJson,"time"));
    SoketData ("date", date, jsonRead(configJson,"date"));
    jsonWrite(configJson, "time", timeS); // отправить время в configJson
    jsonWrite(configJson, "date", date); // отправить дату в configJson
  }, nullptr, true);
}
/* ---------------- Задание для закрепления материала
    Заставьте мигать светодиод на любом pin с частотой 5 секунд
    сделайте новую задачу под индексом 2
    в /config.live.json отправляйте состояние светодиода с ключем "stateLed"
    Выводите состояние светодиода на график по запросу вида /charts.json?data=stateLed
    Процедуру blink_init() инициализируйте в setup
*/

void blink_init() {
  // здесь пишите код решения
}
