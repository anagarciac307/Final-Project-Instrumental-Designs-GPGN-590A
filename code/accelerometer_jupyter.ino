#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

//software SPI
#define LIS3DH_CLK 13
#define LIS3DH_MISO 12
#define LIS3DH_MOSI 11
// Used for hardware & software SPI
#define LIS3DH_CS 10

// software SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS, LIS3DH_MOSI, LIS3DH_MISO, LIS3DH_CLK);
// hardware SPI
//Adafruit_LIS3DH lis = Adafruit_LIS3DH(LIS3DH_CS);
// I2C
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

void setup(void) 
{
  Serial.begin(115200);
  while (!Serial) delay(10);


  if (! lis.begin(0x18)) 
  {
    while (1) yield();
  }

  lis.setRange(LIS3DH_RANGE_4_G);

//  Serial.print("Range = "); Serial.print(2 << lis.getRange());
//  Serial.println("G");

  lis.setDataRate(LIS3DH_DATARATE_10_HZ);
//  Serial.print("Data rate set to: ");
//  switch (lis.getDataRate()) {
//    case LIS3DH_DATARATE_1_HZ: Serial.println("1 Hz"); break;
//    case LIS3DH_DATARATE_10_HZ: Serial.println("10 Hz"); break;
//    case LIS3DH_DATARATE_25_HZ: Serial.println("25 Hz"); break;
//    case LIS3DH_DATARATE_50_HZ: Serial.println("50 Hz"); break;
//    case LIS3DH_DATARATE_100_HZ: Serial.println("100 Hz"); break;
//    case LIS3DH_DATARATE_200_HZ: Serial.println("200 Hz"); break;
//    case LIS3DH_DATARATE_400_HZ: Serial.println("400 Hz"); break;
//
//    case LIS3DH_DATARATE_POWERDOWN: Serial.println("Powered Down"); break;
//    case LIS3DH_DATARATE_LOWPOWER_5KHZ: Serial.println("5 Khz Low Power"); break;
//    case LIS3DH_DATARATE_LOWPOWER_1K6HZ: Serial.println("16 Khz Low Power"); break;
//  }
}

void loop() 
{
  lis.read();
  // Then print out the raw data
//  Serial.print("X:  "); Serial.print(lis.x);
//  Serial.print("  \tY:  "); Serial.print(lis.y);
//  Serial.print("  \tZ:  "); Serial.print(lis.z);

  sensors_event_t event;
  lis.getEvent(&event);

  /* Display the results (acceleration is measured in m/s^2) */
  Serial.print(event.acceleration.x);
  Serial.print(",");
  Serial.print(event.acceleration.y);
  Serial.print(",");
  Serial.print(event.acceleration.z);

  Serial.println();

  delay(200);
}
