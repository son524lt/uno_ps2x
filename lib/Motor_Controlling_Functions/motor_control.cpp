#include <Arduino.h>
#include <motor_control.h>

Motor::Motor(int8_t forward_pin, int8_t backward_pin) {
    forward = forward_pin;
    backward = backward_pin;
    pinMode(forward,OUTPUT);
    pinMode(backward,OUTPUT);
}

void Motor::Run(int pwm) {
    if (pwm>255) pwm = 255;
    else if (pwm<-255) pwm = -255;
    analogWrite(forward, (pwm>0)?(pwm):(0));
    analogWrite(backward, (pwm>0)?(0):(-pwm));
}

void Motor::Break() {
    analogWrite(forward,255);
    analogWrite(backward,255);
}
