#include <Adafruit_CircuitPlayground.h>

struct rgbColor {
  short r = 0;    
  short g = 0;   
  short b = 0;  
};

rgbColor color;

float timer = 0;

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() {
//  CircuitPlayground.clearPixels();

  for(int i = 0; i < 10; i++)
  {
    IncrementColors();
    CircuitPlayground.setPixelColor(i, color.r,   color.g,   color.b);
    delay(100);
  }
}

void IncrementColors()
{
  timer = timer + .1;
  color.r = ProcessVal(sin(timer) * 255);
  color.g = ProcessVal(sin(timer - .5) * 255);
  color.b = ProcessVal(sin(timer - 1.0) * 255);

//  PrintToSerial(color);
}

int ProcessVal(double val)
{
  if (val > 255)
    val = 255;
  else if(val < 0)
    val = 0;

  return val;
}

void PrintToSerial(rgbColor c)
{
  Serial.print("R:");
  Serial.print(c.r);
  Serial.print("  G:");
  Serial.print(c.g);
  Serial.print("  B:");
  Serial.print(c.b);
  Serial.print('\n');
}

