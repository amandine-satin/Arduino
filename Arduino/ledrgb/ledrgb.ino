#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Adafruit_NeoPixel.h>

#define PIN            23
#define NUMPIXELS      16

Adafruit_BME280 bme;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  if (!bme.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  pixels.begin();
}

void loop() {
  float temperature = bme.readTemperature();
  float humidity = bme.readHumidity();
  float pressure = bme.readPressure() / 100.0F;

  displayBarGraph(temperature, pixels.Color(255, 0, 0),20,25); // Red for temperature
  delay(5000); // Wait for 5 seconds

  displayBarGraph(humidity, pixels.Color(0, 0, 255),0,100); // Blue for humidity
  delay(5000); // Wait for 5 seconds

  displayBarGraph(pressure, pixels.Color(0, 255, 0),900,1100); // Green for pressure
  delay(5000); // Wait for 5 seconds
}

void displayBarGraph(float value, uint32_t color,int min,int max) {
  int pixelsToLight = map(value,min, max, 0, NUMPIXELS);

  pixels.clear();

  for(int i=0; i<pixelsToLight; i++)
    pixels.setPixelColor(i, color);

  pixels.show();
}
