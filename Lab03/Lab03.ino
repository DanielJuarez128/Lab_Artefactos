#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3C

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SH1106G display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

const int LM35 = A0;
int lectura;
float temperatura;

void setup() {

  Serial.begin(9600);

  lectura = analogRead(A0);
  temperatura = lectura * (5.0 / 1023) * 100;
  
  Wire.begin();

  delay(250);

  if (!display.begin(i2c_Address, true)) {
    Serial.println("ERROR: OLED no encontrada");

    while (1);
  }

  Serial.println("OLED funcionando correctamente");

  display.clearDisplay();
  display.setTextColor(SH110X_WHITE);

  
  display.setTextSize(1);
  display.setCursor(15, 10);
  display.println("Temperatura:");

  display.setTextSize(1);
  display.setCursor(15, 40);
  display.print(temperatura);
  display.print(" C");

  display.display();
}

void loop() {
  
}