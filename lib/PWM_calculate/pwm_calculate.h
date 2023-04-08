#ifndef _PWM_CALCULATE_H_
#define _PWM_CALCULATE_H_

class pwmCalculator
{
private:
    /* data */
public:
    pwmCalculator(int *BASE_PWM, int *PWM_SEN, int pwmLen, int sensLen, int pwmLv, int sensLv);
    int preX = 0, preY = 0, leftPWM, rightPWM, pwmLen, sensLen, pwmLv, sensLv, xValue, yValue;
    int* BASE_PWM;
    int* PWM_SEN;
    void calculatePWM(int x, int y);
    void Debug(HardwareSerial &_Serial);
    void changeBasePWM(bool gain);
    void changePWMsens(bool gain);
};

#endif