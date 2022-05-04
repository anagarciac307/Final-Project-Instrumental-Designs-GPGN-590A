
#include <Wire.h>
#include <SPI.h>
#include <TouchScreen.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <SD.h>

#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define YP A6
#define XM A7
#define YM 9
#define XP 8
#define TS_MINX 115
#define TS_MINY 124
#define TS_MAXX 914
#define TS_MAXY 934
#define MINPRESSURE 10000
#define MAXPRESSURE 100000

MCUFRIEND_kbv tft;
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 372);
Adafruit_LIS3DH accel = Adafruit_LIS3DH();

int x_pos;
float y_pos_x;
float y_pos_x_old = 160;
float y_pos_y;
float y_pos_y_old = 160;
float y_pos_z;
float y_pos_z_old = 160;
byte x_scale = 1;
byte y_scale = 1;
int accel_x;
int accel_y;
int accel_z;
const int SD_CS = 4;


void setup() 
{
  Serial.begin(9600);
  while (!Serial) delay(10);   


  if (! accel.begin(0x18)) 
  {
    while (1) yield();
  }  

  uint16_t ID = tft.readID();
  tft.begin(ID);
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  
  pinMode(SD_CS, OUTPUT);
  SD.begin(SD_CS);  
  File logFile = SD.open("LOG1.csv", FILE_WRITE);
  if (logFile)
  {
    logFile.println(", , ,");
    String header = "X, Y, Z";
    logFile.println(header);
    logFile.close();
  }  

  accel.setRange(LIS3DH_RANGE_4_G);
  accel.setDataRate(LIS3DH_DATARATE_10_HZ);

  tftDrawGraphObjects();
  tftDrawColorKey();

}


void loop() 
{
  
  accel.read();

  for (x_pos = (11 + x_scale); x_pos <= 470; x_pos += x_scale)
  {

    TSPoint p = ts.getPoint();
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    p.x = map(p.x, TS_MINX, TS_MAXX, 0, tft.height());
    p.y = map(p.y, TS_MINY, TS_MAXY, tft.width(), 0);

    if (p.z > MINPRESSURE && p.z < MAXPRESSURE)
    {

      if ( (p.y >= 210 && p.y <= 230) && (p.x >= 0 && p.x <= 20) )
      {
        if (x_scale > 1)
        {
          x_scale --;
          delay(70);
          tft.fillRect(256, 21, 6, 8, BLACK);
          tft.setCursor(254, 21);
          tft.setTextSize(1);
          tft.setTextColor(WHITE);
          tft.print(x_scale);
          break;
        }
      }
      if ( (p.y >= 239 && p.y <= 259) && (p.x >= 0 && p.x <= 20) )
      {
        if (x_scale < 6)
        {
          x_scale ++;
          delay(70);
          tft.fillRect(256, 21, 6, 8, BLACK);
          tft.setCursor(254, 21);
          tft.setTextSize(1);
          tft.setTextColor(WHITE);
          tft.print(x_scale);
          break;
        }
      }

      if ( (p.y >= 266 && p.y <= 286) && (p.x >= 0 && p.x <= 20) )
      {
        if (y_scale > 1)
        {
          y_scale --;
          delay(70);
          tft.fillRect(312, 21, 6, 8, BLACK);
          tft.setCursor(311, 21);
          tft.setTextSize(1);
          tft.setTextColor(WHITE);
          tft.print(y_scale);
          break;
        }
      }
      if ( (p.y >= 295 && p.y <= 315) && (p.x >= 0 && p.x <= 20) )
      {
        if (y_scale < 8)
        {
          y_scale ++;
          delay(70);
          tft.fillRect(312, 21, 6, 8, BLACK);
          tft.setCursor(310, 21);
          tft.setTextSize(1);
          tft.setTextColor(WHITE);
          tft.print(y_scale);
          break;
        }
      }
    }


    sensors_event_t event;
    accel.getEvent(&event);

    y_pos_x = ((-event.acceleration.x * (y_scale * 10)) + 160);
    y_pos_y = ((-event.acceleration.y * (y_scale * 10)) + 160);
    y_pos_z = ((-event.acceleration.z * (y_scale * 10)) + 160);

    tft.drawLine(x_pos + x_scale, y_pos_x_old, x_pos, y_pos_x, GREEN);
    tft.drawLine(x_pos + x_scale, y_pos_y_old, x_pos, y_pos_y, RED);
    tft.drawLine(x_pos + x_scale, y_pos_z_old, x_pos, y_pos_z, BLUE);


    if ((x_pos >= 0) && (x_pos <= 470))
    {
      tft.fillRect(x_pos + 1, 0, 10, 160, BLACK);
    }
    if ((x_pos >= 0) && (x_pos <= 470))
    {
      tft.fillRect(x_pos + 1, 161, 10, 88, BLACK);
    }
    else
    {
      tft.fillRect(x_pos + 1, 161, 10, 159, BLACK);
    }

    y_pos_x_old = y_pos_x;
    y_pos_y_old = y_pos_y;
    y_pos_z_old = y_pos_z;

    Serial.print(event.acceleration.x);Serial.print(",");Serial.print(event.acceleration.y);Serial.print(",");Serial.print(event.acceleration.z);Serial.println();

    String DataString = String(event.acceleration.x) + " , " + String(event.acceleration.y) + " , " + String(event.acceleration.z);
    File logFile = SD.open("LOG1.csv", FILE_WRITE);
    if (logFile)
    {
      logFile.println(DataString);
      logFile.close();
    }

    tftDrawGraphObjects();
    tftDrawColorKey();
  }
}


void tftDrawColorKey() 
{
  tft.setTextSize(1); tft.setTextColor(WHITE);
  tft.fillRect(400, 282, 15, 8, GREEN); tft.setCursor(416, 282); tft.print(" - X");
  tft.fillRect(400, 290, 15, 8, RED); tft.setCursor(416, 290); tft.print(" - Y");
  tft.fillRect(400, 298, 15, 8, BLUE); tft.setCursor(416, 298); tft.print(" - Z");
}

void tftDrawGraphObjects() 
{
  tft.fillRect(11, 5, x_scale + 1, 120, BLACK);
  tft.fillRect(11, 121, x_scale + 1, 119, BLACK);
  tft.drawFastVLine(10, 5, 310, WHITE); // y axis
  tft.drawFastHLine(10, 160, 470, WHITE); // x axis
  tft.setTextColor(YELLOW); tft.setTextSize(1); //y axis labels
  tft.setCursor(3, 155); tft.print("0");  // "0" at center of ya axis
  tft.setCursor(3, 6); tft.print("+"); // "+' at top of y axis
  tft.setCursor(3, 315); tft.print("-"); // "-" at bottom of y axis
}
