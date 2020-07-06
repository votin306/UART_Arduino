#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <Servo.h>
#include <Adafruit_BMP085.h>
#include <FastLED.h>

Servo myservo;
void(* resetFunc) (void) = 0;
Adafruit_BMP085 bmp;

char sec[10];
char mins[10];
char hours[10];
char days[10];
char moht[10];
char years[10];

int trigPin = 4;
int echoPin = 7;

#define NUM_LEDS 8
#define DATA_PIN 2
CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  myservo.attach(5);
  for (int pin_i ; pin_i < 13 ; pin_i++) {
    digitalWrite(pin_i, LOW);
  }
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  }
  FastLED.setBrightness(50);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  tmElements_t tm;
  if (RTC.read(tm)) {
    String elapsedTime = String(tm.Second);
    elapsedTime.toCharArray(sec, 10);
    String elapsedTime1 = String(tm.Minute);
    elapsedTime1.toCharArray(mins, 10);
    String elapsedTime2 = String(tm.Hour);
    elapsedTime2.toCharArray(hours, 10);
    String elapsedTime3 = String(tm.Day);
    elapsedTime3.toCharArray(days, 10);
    String elapsedTime4 = String(tm.Month);
    elapsedTime4.toCharArray(moht, 10);
    String elapsedTime5 = String(tmYearToCalendar(tm.Year));
    elapsedTime5.toCharArray(years, 10);
  }
  if (Serial.available()) {
    int buff = Serial.parseInt();
    switch (buff) {
      case 20101 : digiWrite(2, 1);
        break;
      case 30101 : digiWrite(3, 1);
        break;
      case 40101 : digiWrite(4, 1);
        break;
      case 50101 : digiWrite(5, 1);
        break;
      case 60101 : digiWrite(6, 1);
        break;
      case 70101 : digiWrite(7, 1);
        break;
      case 80101 : digiWrite(8, 1);
        break;
      case 90101 : digiWrite(9, 1);
        break;
      case 100101 : digiWrite(10, 1);
        break;
      case 110101 : digiWrite(11, 1);
        break;
      case 120101 : digiWrite(12, 1);
        break;
      case 20001 : digiWrite(2, 0);
        break;
      case 30001 : digiWrite(3, 0);
        break;
      case 40001 : digiWrite(4, 0);
        break;
      case 50001 : digiWrite(5, 0);
        break;
      case 60001 : digiWrite(6, 0);
        break;
      case 70001 : digiWrite(7, 0);
        break;
      case 80001 : digiWrite(8, 0);
        break;
      case 90001 : digiWrite(9, 0);
        break;
      case 100001 : digiWrite(10, 0);
        break;
      case 110001 : digiWrite(11, 0);
        break;
      case 120001 : digiWrite(12, 0);
        break;
      case 20201 : digiRead(2);
        break;
      case 30201 : digiRead(3);
        break;
      case 40201 : digiRead(4);
        break;
      case 50201 : digiRead(5);
        break;
      case 60201 : digiRead(6);
        break;
      case 70201 : digiRead(7);
        break;
      case 80201 : digiRead(8);
        break;
      case 90201 : digiRead(9);
        break;
      case 100201 : digiRead(10);
        break;
      case 110201 : digiRead(11);
        break;
      case 120201 : digiRead(12);
        break;
      case 002 : analoRead(0);
        break;
      case 102 : analoRead(1);
        break;
      case 202 : analoRead(2);
        break;
      case 302 : analoRead(3);
        break;
      case 402 : analoRead(4);
        break;
      case 502 : analoRead(5);
        break;
      case 602 : analoRead(6);
        break;
      case 702 : analoRead(7);
        break;
      case 30003 : Run_PWM(3, 0);
        break;
      case 306403 : Run_PWM(3, 64);
        break;
      case 3019103 : Run_PWM(3, 191);
        break;
      case 3025503 : Run_PWM(3, 255);
        break;
      case 10 : Serial.println("Перезагрузка"); delay(1000); resetFunc();
        break;
      case 20 : times();
        break;
      case 3000 : write_servo(0);
        break;
      case 30045 : write_servo(45);
        break;
      case 30090 : write_servo(90);
        break;
      case 300135 : write_servo(135);
        break;
      case 300180 : write_servo(180);
        break;
      case 4001 : sounds(150, 1);
        break;
      case 4000 : sounds(0, 0);
        break;
      case 50 : BMPread();
        break;
      case 6001 : runRGB(1);
        break;
      case 6002 : runRGB(2);
        break;
      case 6003 : runRGB(3);
        break;
      case 6004 : runRGB(4);
        break;
      case 6005 : runRGB(5);
        break;
      case 70 : readUS();
        break;
    }
  }
}
