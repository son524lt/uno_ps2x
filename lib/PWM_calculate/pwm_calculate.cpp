#include <Arduino.h>
#include <pwm_calculate.h>

pwmCalculator::pwmCalculator(int* _BASE_PWM, int* _PWM_SEN, int _pwmLen, int _sensLen, int _pwmLv, int _sensLv) {
    BASE_PWM = _BASE_PWM;
    PWM_SEN = _PWM_SEN;
    pwmLen = _pwmLen;
    sensLen = _sensLen;
    pwmLv = _pwmLv;
    sensLv = _sensLv;
}

void pwmCalculator::calculatePWM(int x, int y) {
    xValue = map(x,0,255,-PWM_SEN[sensLv],PWM_SEN[sensLv]);
    yValue = map(y,255,0,-BASE_PWM[pwmLv],BASE_PWM[pwmLv]);

    xValue = (xValue>=5||xValue<=-5)?xValue:0;
    yValue = (yValue>=5||yValue<=-5)?yValue:0;

    rightPWM = (yValue<0)?(yValue+xValue):(yValue-xValue);
    leftPWM = (yValue<0)?(yValue-xValue):(yValue+xValue);

    preY = yValue;
    preX = xValue;
}

void pwmCalculator::Debug(HardwareSerial &_Serial) {
    _Serial.print(preX);
    _Serial.print("\t");
    _Serial.print(preY);
    _Serial.print("\t");
    _Serial.print(xValue);
    _Serial.print("\t");
    _Serial.print(yValue);
    _Serial.print("\t");
    _Serial.print(leftPWM);
    _Serial.print("\t");
    _Serial.println(rightPWM);
}

void pwmCalculator::changeBasePWM(bool gain) {
    if (gain) {
        pwmLv++;
        if (pwmLv >= pwmLen) {
            pwmLv = pwmLen-1;
        }
    } else {
        pwmLv--;
        if (pwmLv <0) {
            pwmLv = 0;
        }
    }
};
void pwmCalculator::changePWMsens(bool gain) {
    if (gain) {
        sensLv++;
        if (sensLv >= sensLen) {
            sensLv = sensLen-1;
        }
    } else {
        sensLv--;
        if (sensLv <0) {
            sensLv = 0;
        }
    }
};