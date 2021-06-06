#define BUTTON_PIN_1 7

#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

bool oldDirection = true;
bool buttonState_1 = true;
bool buttonState_2 = false;
int stepNumber = 0;

void one_step (bool direction) {
  if (direction) {
    switch(stepNumber) {
      case 0:
          digitalWrite(STEPPER_PIN_1, HIGH);
          digitalWrite(STEPPER_PIN_2, LOW);
          digitalWrite(STEPPER_PIN_3, LOW);
          digitalWrite(STEPPER_PIN_4, LOW);
          break;
      case 1:
          digitalWrite(STEPPER_PIN_1, LOW);
          digitalWrite(STEPPER_PIN_2, HIGH);
          digitalWrite(STEPPER_PIN_3, LOW);
          digitalWrite(STEPPER_PIN_4, LOW);
          break;
      case 2:
          digitalWrite(STEPPER_PIN_1, LOW);
          digitalWrite(STEPPER_PIN_2, LOW);
          digitalWrite(STEPPER_PIN_3, HIGH);
          digitalWrite(STEPPER_PIN_4, LOW);
          break;
      case 3:
          digitalWrite(STEPPER_PIN_1, LOW);
          digitalWrite(STEPPER_PIN_2, LOW);
          digitalWrite(STEPPER_PIN_3, LOW);
          digitalWrite(STEPPER_PIN_4, HIGH);
          break;
    }
  } else {
    switch (stepNumber) {
      case 0 :
          digitalWrite(STEPPER_PIN_1, LOW);
          digitalWrite(STEPPER_PIN_2, LOW);
          digitalWrite(STEPPER_PIN_3, LOW);
          digitalWrite(STEPPER_PIN_4, HIGH);
          break;
      case 1:
          digitalWrite(STEPPER_PIN_1, LOW);
          digitalWrite(STEPPER_PIN_2, LOW);
          digitalWrite(STEPPER_PIN_3, HIGH);
          digitalWrite(STEPPER_PIN_4, LOW);
          break;
      case 2:
          digitalWrite(STEPPER_PIN_1, LOW);
          digitalWrite(STEPPER_PIN_2, HIGH);
          digitalWrite(STEPPER_PIN_3, LOW);
          digitalWrite(STEPPER_PIN_4, LOW);
          break;
      case 3:
          digitalWrite(STEPPER_PIN_1, HIGH);
          digitalWrite(STEPPER_PIN_2, LOW);
          digitalWrite(STEPPER_PIN_3, LOW);
          digitalWrite(STEPPER_PIN_4, LOW);
          break;
    }
  }
  
  stepNumber++;
  if (stepNumber > 3)
      stepNumber = 0;
}
  void setup() {
    pinMode(BUTTON_PIN_1, INPUT_PULLUP);
    pinMode(STEPPER_PIN_1, OUTPUT);
    pinMode(STEPPER_PIN_2, OUTPUT);
    pinMode(STEPPER_PIN_3, OUTPUT);
    pinMode(STEPPER_PIN_4, OUTPUT);
  }

  void loop() {
    buttonState_1 = digitalRead(BUTTON_PIN_1);
    if (buttonState_1 == LOW) {
      if (oldDirection) {
        for (int i = 0; i < 1400; i++) {
          one_step(true);
          delay(2);
        }
        oldDirection = false;
      } else {
        for (int i = 0; i < 1400; i++) {
          one_step(true);
          delay(2);
        }
        oldDirection = true;
      }
    }
  }
