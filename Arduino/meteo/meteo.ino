#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define PIN            23
#define NUMPIXELS      16

#define SCREEN_WIDTH  128
#define SCREEN_HEIGHT  32
#define OLED_RESET    -1

Adafruit_BME280 bme;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  pixels.begin();

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
}

void loop() {
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F;

  displayBarGraph(temperature, pixels.Color(255, 0, 0)); // Red for temperature
  displayValuesOnOLED(temperature, humidity, pressure);
  delay(5000); // Wait for 5 seconds

  displayBarGraph(humidity, pixels.Color(0, 0, 255)); // Blue for humidity
  displayValuesOnOLED(temperature, humidity, pressure);
  delay(5000); // Wait for 5 seconds

  displayBarGraph(pressure, pixels.Color(0, 255, 0)); // Green for pressure
  displayValuesOnOLED(temperature, humidity, pressure);
  delay(5000); // Wait for 5 seconds
}

void displayBarGraph(float value, uint32_t color) {
  int pixelsToLight = map(value, 0, 100, 0, NUMPIXELS);

  pixels.clear();

  for(int i=0; i<pixelsToLight; i++)
    pixels.setPixelColor(i, color);

  pixels.show();
}

void displayValuesOnOLED(float temperature, float humidity, float pressure) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print(F("Temperature: "));
  display.print(temperature);
  display.println(F(" C"));

  display.print(F("Humidity: "));
  display.print(humidity);
  display.println(F("%"));

  display.print(F("Pressure: "));
  display.print(pressure);
  display.println(F(" hPa"));
  display.display();
}




