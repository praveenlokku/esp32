// ESP-WROOM-32 Touch Control
#define TOUCH_DOWN T0  // GPIO 4 (Touch0)
#define TOUCH_UP   T3  // GPIO 15 (Touch3)

void setup() {
  Serial.begin(115200);
  // Disable built-in pullups (important!)
  touchAttachInterrupt(TOUCH_DOWN, NULL, 30); 
  touchAttachInterrupt(TOUCH_UP, NULL, 30);
}

void loop() {
  if(touchRead(TOUCH_DOWN) < 25) {  // Lower value = touched
    Serial.println("VOL_DOWN");
    delay(300);
  }
  
  if(touchRead(TOUCH_UP) < 25) {
    Serial.println("VOL_UP");
    delay(300);
  }
  delay(10);
}