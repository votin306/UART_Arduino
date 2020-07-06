void digiWrite(int pin_d , int sost) {
  Serial.println("");
  pinMode(pin_d, OUTPUT);
  digitalWrite(pin_d, sost);
  Serial.print("На цифровом пине "); Serial.print(pin_d); Serial.print(" Напряжение "); Serial.print(sost);
}

void digiRead(int pin_dr) {
  Serial.println();
  word val_pin;
  pinMode(pin_dr, INPUT);
  val_pin = digitalRead(pin_dr);
  Serial.println(val_pin);
}

void analoRead(int pin_a) {
  Serial.println();
  word val_pin_a;
  pinMode(pin_a, INPUT);
  val_pin_a = analogRead(pin_a);
  Serial.println(val_pin_a);
}

void Run_PWM(int pin_pwm , int freq) {
  Serial.println("");
  pinMode(pin_pwm, OUTPUT);
  analogWrite(pin_pwm, freq);
  Serial.print("На цифровом пине "); Serial.print(pin_pwm); Serial.print(" Запущен ШИМ с частатой "); Serial.print(freq);

}

void write_servo(int pos) {
  Serial.println("");
  myservo.write(pos);
  Serial.print("Сервопривод повернут на "); Serial.print(pos); Serial.print(" градусов ");

}

void times() {
  Serial.println();
  Serial.print("clock = ");
  Serial.print(hours);
  Serial.print(":");
  Serial.print(mins);
  Serial.print(":");
  Serial.print(sec);
  Serial.println();
  Serial.print("date = ");
  Serial.print(days);
  Serial.print(":");
  Serial.print(moht);
  Serial.print(":");
  Serial.print(years);
}

void sounds(int frenq , int sost) {
  if (sost == 1) {
    tone(6, frenq);
    Serial.println();
    Serial.print("Включен звук");
    Serial.println("");
  }
  if (sost == 0) {
    noTone(6);
    Serial.println();
    Serial.print("Выключен звук");
    Serial.println("");
  }
}

void BMPread() {
  Serial.println();
  Serial.print("Температура = "); Serial.print(bmp.readTemperature()); Serial.print(" * С"); Serial.println();
  Serial.print("Давление = "); Serial.print(bmp.readPressure()); Serial.print(" * PA"); Serial.println();
  Serial.print("Высота над уровнем моря = "); Serial.print(bmp.readAltitude()); Serial.print(" метров"); Serial.println();
  Serial.print("Давление над уровнем моря = "); Serial.print(bmp.readSealevelPressure()); Serial.print(" * PA"); Serial.println();
}

void runRGB(int colors) {
  if (colors == 1) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Red;
    }
    FastLED.show();
  }
  if (colors == 2) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Green;
    }
    FastLED.show();
  }
  if (colors == 3) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Blue;
    }
    FastLED.show();
  }
  if (colors == 4) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Yellow;
    }
    FastLED.show();
  }
  if (colors == 5) {
    for (int i = 0; i < NUM_LEDS; i++) {
      leds[i] = CRGB::Black;
    }
    FastLED.show();
  }
}

void readUS() {
  int duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;
  Serial.print(distance); 
  Serial.println(" cm");
}
