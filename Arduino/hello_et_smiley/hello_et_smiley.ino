/**************************************************************************
 This is an example for our Monochrome OLEDs based on SSD1306 drivers

 Pick one up today in the adafruit shop!
 ------> http://www.adafruit.com/category/63_98

 This example is for a 128x32 pixel display using I2C to communicate
 3 pins are required to interface (two I2C and one reset).

 Adafruit invests time and resources providing this open
 source code, please support Adafruit and open-source
 hardware by purchasing products from Adafruit!

 Written by Limor Fried/Ladyada for Adafruit Industries,
 with contributions from the open source community.
 BSD license, check license.txt for more information
 All text above, and the splash screen below must be
 included in any redistribution.
 **************************************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // largeur de l'écran OLED
#define SCREEN_HEIGHT 32 // hauteur de l'écran OLED

// Déclaration pour un écran SSD1306 connecté via I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

// Tableau de bits pour un smiley
static const unsigned char PROGMEM smiley[] =
{ 
  0x3C, 0x42, 0xA5, 0x81, 0xA5, 0x99, 0x42, 0x3C
};

void setup() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Adresse 0x3C pour un écran 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Ne quittez pas, l'initialisation a échoué
  }

  display.clearDisplay();
  display.setTextSize(1);             // Taille du texte
  display.setTextColor(WHITE);        // Couleur du texte
  display.setCursor(0, 0);            // Position du curseur
  display.println("Hello World !");   // Texte à afficher
  display.drawBitmap(90, 10, smiley, 8, 8, 1); // Affiche le smiley à la position x=90, y=10
  display.display(); // Mettez à jour l'écran avec tout ce que nous avons écrit
}

void loop() {
  // le code à exécuter en boucle
}

