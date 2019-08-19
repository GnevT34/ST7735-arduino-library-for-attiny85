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

void setup()
{
//  OSCCAL = 0xae;  // ~20MHz ATtiny overclock
//  OSCCAL = 0xd0;  // ~25MHz ATtiny overclock
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
  tft.fillScreen(ST7735_BLACK);
}

void loop() 
{
//  rotateLine();
//  rotateText();
//  rotatePixel();
//  rotateFastline();
//  rotateDrawrect();
//  rotateFillrect();
//  rotateDrawcircle();
//  rotateFillcircle();
//  rotateTriangle();
//  rotateFillTriangle();
//  rotateRoundRect();

    tft.setCursor(0, 30);
    tft.setTextColor(ST7735_RED);
    tft.setTextSize(1);
    tft.println("Hello World!");
    tft.setTextColor(ST7735_YELLOW);
    tft.setTextSize(2);
    tft.println("Hello World!");
    tft.setTextColor(ST7735_GREEN);
    tft.setTextSize(3);
    tft.println("Hello World!");
    tft.setTextColor(ST7735_BLUE);
    tft.setTextSize(4);
    tft.print(omm);
//  rotateFillRoundRect();
//  rotateChar();
//  rotateString();
}
void rotateText() {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.setCursor(0, 30);
    tft.setTextColor(ST7735_RED);
    tft.setTextSize(1);
    tft.println("Hello World!");
    tft.setTextColor(ST7735_YELLOW);
    tft.setTextSize(2);
    tft.println("Hello World!");
    tft.setTextColor(ST7735_GREEN);
    tft.setTextSize(3);
    tft.println("Hello World!");
    tft.setTextColor(ST7735_BLUE);
    tft.setTextSize(4);
    tft.print(1234.567);
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();
  
    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateFillcircle(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.fillCircle(10, 30, 10, ST7735_YELLOW);

    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateDrawcircle(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.drawCircle(10, 30, 10, ST7735_YELLOW);
 
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();
  
    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateFillrect(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.fillRect(10, 20, 10, 20, ST7735_GREEN);
 
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateDrawrect(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.drawRect(10, 20, 10, 20, ST7735_GREEN);
 
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateFastline(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.drawFastHLine(0, 20, tft.width(), ST7735_RED);
    tft.drawFastVLine(20, 0, tft.height(), ST7735_BLUE);

    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateLine(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.drawLine(tft.width()/2, tft.height()/2, 0, 0, ST7735_RED);
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotatePixel(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.drawPixel(10,20, ST7735_WHITE);
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateTriangle(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.drawTriangle(20, 10, 10, 30, 30, 30, ST7735_GREEN);
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateFillTriangle(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.fillTriangle(20, 10, 10, 30, 30, 30, ST7735_RED);
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

void rotateRoundRect(void) {
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    //Serial.println(tft.getRotation(), DEC);

    tft.drawRoundRect(20, 10, 25, 15, 5, ST7735_BLUE);
    //while (!Serial.available());
    //Serial.read();  Serial.read();  Serial.read();

    tft.setRotation(tft.getRotation()+1);
  }
}

//void rotateFillRoundRect(void) {
//  for (uint8_t i=0; i<4; i++) {
//    tft.fillScreen(ST7735_BLACK);
//    //Serial.println(tft.getRotation(), DEC);
//
//    tft.fillRoundRect(20, 10, 25, 15, 5, ST7735_CYAN);
//    //while (!Serial.available());
//    //Serial.read();  Serial.read();  Serial.read();
//
//    tft.setRotation(tft.getRotation()+1);
//  }
//}

//void rotateChar(void) {
//  for (uint8_t i=0; i<4; i++) {
//    tft.fillScreen(ST7735_BLACK);
//    //Serial.println(tft.getRotation(), DEC);
//
//    tft.drawChar(25, 15, 'A', ST7735_WHITE, ST7735_WHITE, 1);
//    //while (!Serial.available());
//    //Serial.read();  Serial.read();  Serial.read();
//
//    tft.setRotation(tft.getRotation()+1);
//  }
//}
//
//void rotateString(void) {
//  for (uint8_t i=0; i<4; i++) {
//    tft.fillScreen(ST7735_BLACK);
//    //Serial.println(tft.getRotation(), DEC);
//
//    tft.setCursor(8, 25);
//    tft.setTextSize(1);
//    tft.setTextColor(ST7735_WHITE);
//    tft.print("Adafruit Industries");
//    //while (!Serial.available());
//    //Serial.read();  Serial.read();  Serial.read();
//
//    tft.setRotation(tft.getRotation()+1);
//  }
//}
