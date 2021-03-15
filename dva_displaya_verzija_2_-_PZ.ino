// Include Wire Library for I2C
#include <Wire.h>
 
// Include Adafruit Graphics & OLED libraries
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
 
// Reset pin not used but needed for library
#define OLED_RESET 4
 
// Create an object for each OLED display
Adafruit_SSD1306 display1(OLED_RESET);
Adafruit_SSD1306 display2(OLED_RESET);

void TCA9548A(uint8_t bus)
{
  Wire.beginTransmission(0x70);
  Wire.write(1 << bus);
  Wire.endTransmission();
}
 
void setup() {
  // Start Wire library for I2C
  Wire.begin();
  
  // Set multiplexer to channel 1 and initialize OLED-0 with I2C addr 0x3C
  TCA9548A(1);
  display1.begin(SSD1306_SWITCHCAPVCC, 0x3C);
 
  // initialize OLED-1 with I2C addr 0x60
  TCA9548A(2);
  display2.begin(SSD1306_SWITCHCAPVCC, 0x60);
}
 
void loop() {

  // display 1
  TCA9548A(1);
  display1.clearDisplay();
  display1.setTextSize(2);
  display1.setTextColor(WHITE);
  display1.setCursor(0, 10);
  // Display static text
  display1.println("Hello..");
  display1.display();

  // display 2
  TCA9548A(2);
  display2.clearDisplay();
  display2.setTextSize(2);
  display2.setTextColor(WHITE);
  display2.setCursor(0, 10);
  // Display static text
  display2.println("world!");
  display2.display();

}
