#ifndef _MOTOR_CONTROL_H_
#define _MOTOR_CONTROL_H_

#include "stdint.h"

class Motor {
private:
    /* data */
public:
    int8_t forward, backward;
    Motor(int8_t forward_pin, int8_t backward_pin);
    void Run(int pwm);
    void Break();
};


#endif

