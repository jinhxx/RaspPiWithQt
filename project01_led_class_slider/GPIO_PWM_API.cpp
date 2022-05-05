#include <wiringPi.h>
#include <softPwm.h>
#include <softTone.h>
#include "GPIO_PWM_API.h"

// ------------------ LED -------------------------
LED::LED(int pin) {
    pinNum = pin;
    config();
}

LED::LED(int pin, int duty)
{
    pinNum = pin;
    mDuty = duty;
    config();
}

LED::LED(int pin, int duty, int period)
{
    pinNum = pin;
    mDuty = duty;
    mPeriod = period;
    config();
}

void LED::config() {
    pinMode(pinNum, OUTPUT);
    softPwmCreate(pinNum, mDuty, mPeriod);
}

void LED::on() {
    // digitalWrite(pinNum, HIGH);
    mDuty = 100;
    softPwmWrite(pinNum, mDuty);
}

void LED::off() {
    mDuty = 0;
    softPwmWrite(pinNum, mDuty);
}

void LED::ledPwmWrite(int value) {
    softPwmWrite(pinNum, value);
}

int LED::ledRead() {
    return digitalRead(pinNum);
}

void LED::ledPwmDown() {
    if (mDuty >= 0)
        mDuty -= mUnit;
    else
        mDuty = 0;

    softPwmWrite(pinNum, mDuty);
}

void LED::ledPwmUp() {
    if (mDuty <= mPeriod)
        mDuty += mUnit;
    else
        mDuty = mPeriod;

    softPwmWrite(pinNum, mDuty);
}


// ------------------ Switch -------------------------
Switch::Switch(int pin) {
    pinNum = pin;
    config();
}

void Switch::config() {
    pinMode(pinNum, INPUT);
}

int Switch::switchRead() {
    return digitalRead(pinNum);
}


// ------------------ PIR -------------------------
void PIR::config() {
    pinMode(mPinNum, INPUT);
}

int PIR::dataRead(int pin) {
    return digitalRead(pin);
}

// ------------------ PIEZO -------------------------
void PIEZO::config() {
    softToneCreate(mPinNum);
}

void PIEZO::playTone(int melody) {
    softToneWrite(mPinNum, melody);
    delay(100);
    softToneWrite(mPinNum, 0);
}
