//
// PDQ_ST7735 configuration
//
// You need to include this file above #include "PDQ_ST7735.h" in your sketch.
// Check settings on lines marked with "<=".

// ST7735 has several variations, set your version based on this list (using the color of the "tab" on the screen cover).
// NOTE: The tab colors refer to Adafruit versions, other suppliers may vary (you may have to experiment to find the right one).
enum
{
	ST7735_INITB			= 0,				// 1.8" (128x160) ST7735B chipset (only one type)
	ST7735_INITR_GREENTAB		= 1,				// 1.8" (128x160) ST7735R chipset with green tab (same as ST7735_INITR_18GREENTAB)
	ST7735_INITR_REDTAB		= 2,				// 1.8" (128x160) ST7735R chipset with red tab (same as ST7735_INITR_18REDTAB)
	ST7735_INITR_BLACKTAB		= 3,				// 1.8" (128x160) ST7735S chipset with black tab (same as ST7735_INITR_18BLACKTAB)
	ST7735_INITR_144GREENTAB   	= 4,				// 1.4" (128x128) ST7735R chipset with green tab
	ST7735_INITR_18GREENTAB		= ST7735_INITR_GREENTAB,	// 1.8" (128x160) ST7735R chipset with green tab
	ST7735_INITR_18REDTAB		= ST7735_INITR_REDTAB,		// 1.8" (128x160) ST7735R chipset with red tab
	ST7735_INITR_18BLACKTAB		= ST7735_INITR_BLACKTAB,	// 1.8" (128x160) ST7735S chipset with black tab
};

#define ST7735_CHIPSET		ST7735_INITR_18REDTAB	// <= Set ST7735 LCD chipset/variation here (from above list)

//
// NOTE: It is confusing, but USI SPI on ATtiny does not use the same pins as ISP SPI!
//       Specifically MOSI is really DO pin 1 (even though used as MISO for ISP)
//
// These are based on Arduino ATtiny pins as defined here http://highlowtech.org/?p=1695

// LCD PIN	ATtiny85
// -------	---------
// 1  VCC	  3.3V/5V  (depending on module)
// 2  GND	  GND
// 3* CS	   0
// 4* RESET   3.3V/5V  (depending on module, perhaps through 10K pull-up)
// 5* DC/RS	   3
// 6* SDI/MOSI 1
// 7* SCK	   2
// 8* LED	  3.3V/5V
// 9  SDO/MISO -
//
//  * = Typically only 3.3V safe logic-line (unless board has level converter [ala Adafruit]). Be careful with 5V!

#define	ST7735_CS_PIN		0			// <= /CS pin (chip-select, LOW to get attention of ST7735, HIGH and it ignores SPI bus)
#define	ST7735_DC_PIN		3			// <= DC pin (1=data or 0=command indicator line) also called RS
//#define	ST7735_RST_PIN		RESET			// <= RST pin (optional)
#define	ST7735_MOSI_PIN	1			// <= MOSI pin (if not hardware SPI)
//#define	ST7735_MISO_PIN	0			// <= MISO pin (if not hardware SPI)
#define	ST7735_SCLK_PIN	2			// <= SCLK pin (if not hardware SPI)
// (with hardware SPI some pins dictated by AVR PIN function - as shown above)

// other PDQ library options
#define	ST7735_SAVE_SPCR	0			// <= 0/1 with 1 to save/restore AVR SPI control register (to "play nice" when other SPI use)
