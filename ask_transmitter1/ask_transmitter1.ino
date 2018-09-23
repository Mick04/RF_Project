// ask_transmitter.pde


#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver(2000, 2, D5, 5); // ESP8266 or ESP32: do not use pin 11 or 2

void setup()
{
    Serial.begin(115200);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    const char *msg = "hello";

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();
    delay(200);
}
