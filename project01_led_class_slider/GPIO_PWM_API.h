#ifndef GPIO_PWM_API_H
#define GPIO_PWM_API_H
class LED
{
    private:
        int pinNum;
    public:
        int mPeriod = 100;
        int mDuty = 0;
        int mUnit = mPeriod/10;

        LED(int pin);
        LED(int pin, int duty);
        LED(int pin, int duty, int period);

        void config();
        void on();
        void off();
        void ledPwmWrite(int value);
        void ledPwmDown();
        void ledPwmUp();
        int ledRead();
};

class Switch {
    private:
        int pinNum;
        int switchState;
    public:
        // EdgeSwitch();
        Switch(int pin);
        void config();
        int switchRead();
};

class PIR
{
    int mPinNum;
    public:
        void config();
        int dataRead(int pin);
};

class PIEZO
{
    int mPinNum;
    int aMelody[8] = {523,587,659,698,783,880,987,1046};
    public:
        void config();
        void playTone(int melody);
};
#endif // GPIO_PWM_API_H

