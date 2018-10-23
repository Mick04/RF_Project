// ask_receiver.pde

//llllllll
#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, D5, 2, 5); // ESP8266 or ESP32: do not use pin 11 or 2

void setup()
{
    Serial.begin(115200);	// Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
    uint8_t buflen = sizeof(buf);
    //driver.printBuffer("Got:", buf, buflen);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      // Message with a good checksum received, dump it.
      //driver.printBuffer("Got:", buf, buflen);
      //Convert to charactor string
      String rcv;
      for (int i = 0; i < buflen; i++){
        rcv += (char)buf[i];
      }
      Serial.println(rcv);
    }
}
