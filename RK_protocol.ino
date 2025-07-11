//compatible con Arduino uno R3 y Mega R3

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DS3231.h>

DS3231 rtc;  // Objeto para el RTC

LiquidCrystal_I2C lcd(0x27, 16, 2);  // LCD I2C 16x2

const int buttonPin = 2;
const int r1 = 3;

boolean z, y, sw, r, x;

uint32_t time_now = 0;
uint32_t time_new = 0;
uint32_t temp1;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(r1, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.print("automatic Kindling");
  delay(2000);
}

void loop() {
  uint16_t h;
  uint8_t m, s;

  if (z == 1 && digitalRead(buttonPin) == 1) {
    while (digitalRead(buttonPin) == 1) { delay(25); }
    z = 0; y = 0;
  }

  if (y == 0) {
    lcd.clear();
    lcd.print("Pulse for start");
    y = 1; sw = 0;
  }

  if (digitalRead(buttonPin) == 1 && sw == 0) {
    while (digitalRead(buttonPin) == 1) { delay(25); }
    time_now = getSecondsNow();
    x = 0;
    lcd.clear();
    lcd.print("Wait R1");
    sw = 1; r = 1;
  }

  time_new = getSecondsNow();

  if (x == 0 && sw == 1) {
    activarEvento(time_now, time_new, 1200, "Wait R2");
    activarEvento(time_now, time_new, 3600, "Wait R3");
    activarEvento(time_now, time_new, 6000, "Wait R4");
    activarEvento(time_now, time_new, 8400, "Wait R5");
    activarEvento(time_now, time_new, 10800, "Wait R6");

    if (time_new == time_now + 13200) {
      digitalWrite(r1, HIGH);
      lcd.setCursor(0, 0); lcd.print("              ");
      lcd.setCursor(8, 0); lcd.print("rele ON ");
    }
    if (time_new == time_now + 13210) {
      digitalWrite(r1, LOW);
      lcd.setCursor(0, 0); lcd.print("Fin de protocolo");
      z = 1;
    }
  }

  lcd.setCursor(0, 1);
  lcd.print(formatTimeString());

  lcd.setCursor(9, 1);
  temp1 = time_new - time_now;
  secondsToHMS(temp1, h, m, s);
  lcd.print(h); lcd.print(":"); lcd.print(m); lcd.print(":"); lcd.print(s);

  if (digitalRead(buttonPin) == 1 && r == 1) {
    r = 0;
    lcd.clear(); lcd.print("cancelado");
    while (digitalRead(buttonPin) == 1) { delay(25); }
    digitalWrite(r1, LOW); y = 0;
  }
}

void secondsToHMS(const uint32_t seconds, uint16_t &h, uint8_t &m, uint8_t &s) {
  uint32_t t = seconds;
  s = t % 60;
  t = (t - s) / 60;
  m = t % 60;
  t = (t - m) / 60;
  h = t;
}

uint32_t getSecondsNow() {
  bool h12, pm;
  return rtc.getHour(h12, pm) * 3600UL + rtc.getMinute() * 60UL + rtc.getSecond();
}

String formatTimeString() {
  bool h12, pm;
  char buffer[12];
  sprintf(buffer, "%02d:%02d:%02d", rtc.getHour(h12, pm), rtc.getMinute(), rtc.getSecond());
  return String(buffer);
}

void activarEvento(uint32_t base, uint32_t actual, uint32_t offset, const char* mensaje) {
  if (actual == base + offset) {
    digitalWrite(r1, HIGH);
    lcd.setCursor(0, 0); lcd.print("              ");
    lcd.setCursor(8, 0); lcd.print("rele ON ");
  }
  if (actual == base + offset + 10) {
    digitalWrite(r1, LOW);
    lcd.setCursor(0, 0); lcd.print(mensaje);
    lcd.setCursor(8, 0); lcd.print("rele OFF");
  }
}
