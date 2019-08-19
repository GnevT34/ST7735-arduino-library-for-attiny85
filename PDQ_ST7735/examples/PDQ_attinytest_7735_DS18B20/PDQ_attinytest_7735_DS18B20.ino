// This is part of the PDQ re-mixed version of Adafruit's GFX library
// and associated chipset drivers.
// Here is the libraries original copyright notice:

/***************************************************
  This is an example sketch for the Adafruit 2.2" SPI display.
  This library works with the Adafruit 2.2" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/1480
 
  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required to
  interface (RST is optional)
  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/
 
//#include "SPI.h"        // must include this here (or else IDE can't find it)
                                        
#include <PDQ_GFX.h>        // PDQ: Core graphics library
#include "PDQ_ST7735_config.h"      // PDQ: ST7735 pins and other setup for this sketch
#include <PDQ_ST7735.h>     // PDQ: Hardware-specific driver library
PDQ_ST7735 tft;     // PDQ: create LCD object (using pins in "PDQ_ST7735_config.h")

// NOTE: Changes to test with Adafruit libraries (comment out PDQ lines above and un-comment the AF: ones below)

// AF: #include <Adafruit_GFX.h>    // AF: Core graphics library
// AF: #include <Adafruit_ST7735.h>   // AF: Hardware-specific library
// AF: Adafruit_ST7735 tft(10,  9, 8);  // AF: create LCD object (HW SPI, CS=pin 10, D/C=pin 8, reset=9)

#include <OneWire.h>   

OneWire  ds(4);

float celsius; 
bool first_Start;

void setup()
{
//  OSCCAL = 0xae;  // ~20MHz ATtiny overclock
//   OSCCAL = 0xd0;  // ~25MHz ATtiny overclock
//  OSCCAL = 0xf2;  // ~30MHz ATtiny overclock
//#if defined(ST7735_RST_PIN) // reset like Adafruit does
//  FastPin<ST7735_RST_PIN>::setOutput();
//  FastPin<ST7735_RST_PIN>::hi();
//  FastPin<ST7735_RST_PIN>::lo();
//  delay(1);
//  FastPin<ST7735_RST_PIN>::hi();
//#endif

  tft.begin();
  tft.setRotation(3);
  //tft.setTextWrap(false); // Allow text to run off right edge
  tft.fillScreen(ST7735_YELLOW);
  first_Start = true;
}

void loop() 
{
  if (first_Start) {
    Screen_Window();  
    first_Start = false;
  }  
  Read_DS18B20();
  PrintVariable();
}

void Screen_Window() {
   tft.fillRect(5, 5, 150, 118, ST7735_BLACK);
   tft.setCursor(40, 95);
   tft.setTextColor(ST7735_RED);
   tft.setTextSize(2);
   tft.print("celsius");
}

void Read_DS18B20() { 
  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];
  
  if ( !ds.search(addr)) {
    //Serial.println("No more addresses.");
    //Serial.println();
    ds.reset_search();
    //delay(250);
    return;
  }
  if (OneWire::crc8(addr, 7) != addr[7]) {
      //Serial.println("CRC is not valid!");
      return;
  }
  ds.reset();
  ds.select(addr);
  ds.write(0x44, 1);       
  //delay(1000);     
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad
  for ( i = 0; i < 9; i++) 
  {
    data[i] = ds.read();
  }
  int16_t raw = (data[1] << 8) | data[0];
  byte cfg = (data[4] & 0x60);
  if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
  else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
  else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
  celsius = (float)raw / 16.0;
}

void PrintVariable() {
  char stringC1[7];
  tft.setCursor(35, 55);
  tft.setTextSize(3);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK); 
  dtostrf(celsius, 7, 3, stringC1); 
  tft.print(stringC1);
}
