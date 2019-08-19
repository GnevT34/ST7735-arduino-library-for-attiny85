NOTE: This file is from the PDQ_ST7735 library.  Thanks PDQ!

This is a library for the Adafruit 1.8" SPI display.
This library works with the Adafruit 1.8" TFT Breakout w/SD card
  ----> http://www.adafruit.com/products/358
The 1.8" TFT shield
  ----> https://www.adafruit.com/product/802
The 1.44" TFT breakout
  ----> https://www.adafruit.com/product/2088
as well as Adafruit raw 1.8" TFT display
  ----> http://www.adafruit.com/products/618

 
//
// NOTE: It is confusing, but USI SPI on ATtiny does not use the same pins as ISP SPI!
//       Specifically MOSI is really DO pin 1 (even though used as MISO for ISP)
//
// These are based on Arduino ATtiny pins as defined here http://highlowtech.org/?p=1695

// LCD PIN	   ATtiny85
// -------	   ---------
// 1  VCC	     3.3V/5V  (depending on module)
// 2  GND	     GND
// 3* CS	     0
// 4* RESET    3.3V/5V  (depending on module, perhaps through 10K pull-up)
// 5* DC/RS	   3
// 6* SDI/MOSI 1
// 7* SCK	     2
// 8* LED	     3.3V/5V
// 9  SDO/MISO -
//
//  * = Typically only 3.3V safe logic-line (unless board has level converter [ala Adafruit]). Be careful with 5V!
