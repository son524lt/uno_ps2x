#include <Arduino.h>
#include <PS2X_lib.h>
#include <motor_control.h>
#include <pwm_calculate.h>

#ifndef _MAIN_H_
#define _MAIN_H_

#define LF 3
#define LB 5
#define RF 6
#define RB 9

#define GAIN 1
#define LOSS 0

void handleClickEvent(PS2X &ps2x, Motor &leftMotor, Motor &rightMotor, pwmCalculator &calculator) {
    if (ps2x.Button(PSB_PAD_LEFT)) {
        calculator.leftPWM=(-calculator.BASE_PWM[calculator.pwmLv]);
        calculator.rightPWM=(calculator.BASE_PWM[calculator.pwmLv]);
    }
    if (ps2x.Button(PSB_PAD_RIGHT)) {
        calculator.leftPWM=(calculator.BASE_PWM[calculator.pwmLv]);
        calculator.rightPWM=(-calculator.BASE_PWM[calculator.pwmLv]);
    }
    if (ps2x.Button(PSB_PAD_UP)) {
        calculator.leftPWM=(calculator.BASE_PWM[calculator.pwmLv]);
        calculator.rightPWM=(calculator.BASE_PWM[calculator.pwmLv]);
    }
    if (ps2x.Button(PSB_PAD_DOWN)) {
        calculator.leftPWM=(-calculator.BASE_PWM[calculator.pwmLv]);
        calculator.rightPWM=(-calculator.BASE_PWM[calculator.pwmLv]);
    }
    if (ps2x.ButtonPressed(PSB_GREEN)) {
        calculator.changeBasePWM(GAIN);
    }
    if (ps2x.ButtonPressed(PSB_BLUE)) {
        calculator.changeBasePWM(LOSS);
    }
    if (ps2x.ButtonPressed(PSB_RED)) {
        calculator.changePWMsens(GAIN);
    }
    if (ps2x.ButtonPressed(PSB_PINK)) {
        calculator.changePWMsens(LOSS);
    }
}

#endif