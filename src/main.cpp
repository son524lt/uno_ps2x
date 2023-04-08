#include <main.h>


PS2X ps2x;
int BASE_PWM[8] = {50, 80, 100, 120, 150, 180, 200, 250}, PWM_SEN[6] = {50, 80, 100, 120, 150, 180};

void setup() {
  ps2x.config_gamepad(12, 11, 10, 13);
  Serial.begin(9600);
}

Motor leftMotor(LF, LB);
Motor rightMotor(RF, RB);
pwmCalculator calculator(BASE_PWM, PWM_SEN, 8, 6, 4, 1);

void loop() {
  ps2x.read_gamepad(0,0);
  calculator.calculatePWM(ps2x.Analog(PSS_LX),ps2x.Analog(PSS_RY));
  handleClickEvent(ps2x, leftMotor, rightMotor, calculator);
  leftMotor.Run(calculator.leftPWM);
  rightMotor.Run(calculator.rightPWM);
  calculator.Debug(Serial);
}