#include <Adafruit_CircuitPlayground.h>

struct rgbColor {
  short r = 0;    
  short g = 0;   
  short b = 0;  
};

rgbColor color;
float timer = 0;
int incrementer = 0;
double frequency = .3;


void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
}

void loop() 
{
  //  CircuitPlayground.clearPixels();
    IncrementColors();
    CircuitPlayground.setPixelColor(0, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(1, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(2, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(3, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(4, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(5, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(6, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(7, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(8, color.r,   color.g,   color.b);
    CircuitPlayground.setPixelColor(9, color.r,   color.g,   color.b);
    delay(100);

    //increment and reset
    incrementer++;
    if(incrementer > 32) 
    {
      incrementer = 0;
    }
}

void IncrementColors()
{
  color.r = ProcessVal(sin(frequency * incrementer + 0) * 255);
  color.g = ProcessVal(sin(frequency * incrementer + 2) * 255);
  color.b = ProcessVal(sin(frequency * incrementer + 4) * 255);

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

