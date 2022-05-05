#ifndef GPIO_PWM_API_H
#define GPIO_PWM_API_H
// GPIO_LED
class GPIO_LED {
    private:
        int mPinNum;
        int mState;
    public:
        GPIO_LED(int pin);
        GPIO_LED(int pin, bool value);
        ~GPIO_LED();
        void ledWrite(bool value);
        bool ledRead(void);
};

// PWM_LED
class PWM_LED {
    private:
        int mPinNum;
        int mDuty;
        int mPeriod;
    public:
        PWM_LED(int pin);
        PWM_LED(int pin, int duty);
        PWM_LED(int pin, int duty, int period);
        ~PWM_LED();
        void setLedBright(int duty);
        void setLedPeriod(int period);
};

// PIR Class
class PirClass
{
    private:
        int mPinNum;
    public:
        PirClass(int pin);
        int dataRead(int pin);
};

// PIEZO Class
class PiezoClass {
    private:
        int mPinNum;
    public:
        PiezoClass(int pin);
        ~PiezoClass();
        void playMelody(int aScale[], int length);
        void playMelody(int notes[], int durations[], int size);
        void playStarwarsBGM();
        void beepSound(unsigned int note, unsigned int duration);
};
#endif // GPIO_PWM_API_H
