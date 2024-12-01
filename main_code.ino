#define IR_SENSOR_RIGHT 11
#define IR_SENSOR_LEFT 12
#define IR_SENSOR_MID 13

#define MOTOR_SPEED 160
#define TURN_SPEED 35

// Motor RIGHT motor connections
int Right_Motor = 3;
int in1 = 5;
int in2 = 4;
// Motor LEFT Motor connections
int Left_Motor = 9;
int in3 = 7;
int in4 = 8;

void setup() {
  Serial.begin(9600);
  // Set all the motor control pins to outputs
  pinMode(Right_Motor, OUTPUT);
  pinMode(Left_Motor, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {

  bool leftV = digitalRead(IR_SENSOR_LEFT);
  bool centerV = digitalRead(IR_SENSOR_MID);
  bool rightV = digitalRead(IR_SENSOR_RIGHT);

  // Serial.println(rightV);
  // Serial.println(centerV);

  if (leftV == 0 && centerV == 1 && rightV == 0) {
    CarForward();
    Serial.println("forward");
  } else if (leftV == 1 && centerV == 1 && rightV == 1) {
    Serial.println("Forward boost");
    CarForward();
  }
  //   delay(300);
  //   bool leftV = digitalRead(IR_SENSOR_LEFT);
  //   bool centerV = digitalRead(IR_SENSOR_MID);
  //   bool rightV = digitalRead(IR_SENSOR_RIGHT);
  //   if (leftV == 0 && centerV == 0 && rightV == 0) {
  //     Serial.println("Sharp Right");
  //     CarTurnRight();
  //     delay(300);
  //   }
  // }

  else if (leftV == 1 && centerV == 1 && rightV == 0) {
    CarTurnLeft();
    Serial.println("Left");

  } else if (leftV == 0 && centerV == 1 && rightV == 1) {
    CarTurnRight();
    Serial.println("Right");

  } else if (leftV == 1 && centerV == 0 && rightV == 0) {
    CarTurnLeft();
    Serial.println("Left");

  } else if (leftV == 0 && centerV == 0 && rightV == 1) {
    CarTurnRight();
    Serial.println("Right");
  }

  // else if (leftV == 0 && centerV == 0 && rightV == 0) {
  //   // Serial.println("Stop");
  //   CarForward();
  // }
}

void CarForward() {
  analogWrite(Right_Motor, MOTOR_SPEED);
  analogWrite(Left_Motor, MOTOR_SPEED);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void CarBackward() {
  analogWrite(Right_Motor, MOTOR_SPEED);
  analogWrite(Left_Motor, MOTOR_SPEED);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void CarTurnLeft() {
  analogWrite(Right_Motor, MOTOR_SPEED + TURN_SPEED);
  analogWrite(Left_Motor, MOTOR_SPEED - TURN_SPEED);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void CarTurnSturnLeft() {
  analogWrite(Right_Motor, MOTOR_SPEED + TURN_SPEED);
  analogWrite(Left_Motor, MOTOR_SPEED - TURN_SPEED);

  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void CarTurnRight() {
  analogWrite(Right_Motor, MOTOR_SPEED - TURN_SPEED);
  analogWrite(Left_Motor, MOTOR_SPEED + TURN_SPEED);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void CarTurnSturnRight() {
  analogWrite(Right_Motor, MOTOR_SPEED - TURN_SPEED);
  analogWrite(Left_Motor, MOTOR_SPEED + TURN_SPEED);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void CarStop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


// This is for Testing the motor connections and its connections
// insert this inside the loop() to test it
void MOTOR_TEST_LOOP() {
  Serial.println("RIGHT MOTOR FRONT");
  analogWrite(Right_Motor, 255);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);

  delay(3000);

  Serial.println("RIGHT MOTOR BACK");
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  delay(3000);
  analogWrite(Right_Motor, 0);

  Serial.println("LEFT MOTOR FRONT");
  analogWrite(Left_Motor, 255);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);

  delay(3000);

  Serial.println("LEFT MOTOR BACK");
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  delay(3000);
  analogWrite(Left_Motor, 0);
}
