#include <iostream>
using namespace std;

#include "GPIO_PWM_API.h"
#include "STARWARSPITCHS.h"
#include <wiringPi.h>
#include <softPwm.h>
#include <softTone.h>

// ====================  GPIO_LED ========================
// 생성자
GPIO_LED::GPIO_LED(int pin) : GPIO_LED(pin, LOW){}

GPIO_LED::GPIO_LED(int pin, bool value) {
    mPinNum = pin;
    mState = value;

    wiringPiSetupGpio();

    pinMode(mPinNum, OUTPUT);
    digitalWrite(mPinNum, mState);
}

// 소멸자
GPIO_LED::~GPIO_LED()
{
    digitalWrite(mPinNum, LOW);
}

// 멤버 함수
void GPIO_LED::ledWrite(bool value)
{
    mState = value;
    digitalWrite(mPinNum, mState);
}

bool GPIO_LED::ledRead(void)
{
    return digitalRead(mPinNum);
}




// ====================  PWM_LED ========================
// 생성자
PWM_LED::PWM_LED(int pin) : PWM_LED(pin, 0, 100){}

PWM_LED::PWM_LED(int pin, int duty) : PWM_LED(pin, duty, 100) {	}

PWM_LED::PWM_LED(int pin, int duty, int period) {
    mPinNum = pin;
    mDuty = duty;
    mPeriod = period;

    wiringPiSetupGpio();

    softPwmCreate(mPinNum, mDuty, mPeriod);
}

// 소멸자
PWM_LED::~PWM_LED()
{
    softPwmStop(mPinNum);
}

// 멤버 함수
void PWM_LED::setLedBright(int duty)
{
    mDuty = duty;
    softPwmWrite (mPinNum, mDuty);
}

void PWM_LED::setLedPeriod(int period)
{
    mPeriod = period;
    softPwmStop(mPinNum);
    softPwmCreate(mPinNum, mDuty, mPeriod);
}

// ====================  PiezoClass ========================
// 생성자
PiezoClass::PiezoClass(int pin) {
    mPinNum = pin;

    wiringPiSetupGpio();

    pinMode(pin, OUTPUT);

    softToneCreate(mPinNum);
}

// 멤버 함수
void PiezoClass::playMelody(int aScale[], int length) {
    // int melody_size = sizeof(aMelody) / sizeof(aMelody[0]);
    for (int i = 0; i < length; i++)
    {
        softToneWrite(mPinNum, aScale[i]);
        delay(200);
    }
}

void PiezoClass::playMelody(int notes[], int durations[], int size) {
    for (int i = 0; i < size; i++)
    {
        beepSound(notes[i], durations[i]);
    }

}

void PiezoClass::beepSound(unsigned int note, unsigned int duration) {
    //This is the semiperiod of each note.
    long beepDelay = (long)(1000000/note);
    //This is how much time we need to spend on the note.
    long time = (long)((duration*1000)/(beepDelay*2));

    for (int i=0 ;i<time; i++)
    {
        //1st semiperiod
        digitalWrite(mPinNum, HIGH);
        delayMicroseconds(beepDelay);
        //2nd semiperiod
        digitalWrite(mPinNum, LOW);
        delayMicroseconds(beepDelay);
    }

    //Add a little delay to separate the single notes
    digitalWrite(mPinNum, LOW);
    delay(20);
}

void PiezoClass::playStarwarsBGM() {
    beepSound(a, 500); beepSound(a, 500); beepSound( f, 350); beepSound( cH, 150);
    beepSound( a, 500);beepSound( f, 350);beepSound( cH, 150);beepSound( a, 1000);beepSound( eH, 500);
    beepSound( eH, 500);beepSound( eH, 500);beepSound( fH, 350);beepSound( cH, 150);beepSound( gS, 500);
    beepSound( f, 350);beepSound( cH, 150);beepSound( a, 1000);beepSound( aH, 500);beepSound( a, 350);
    beepSound( a, 150);beepSound( aH, 500);beepSound( gHS, 250);beepSound( gH, 250);beepSound( fHS, 125);
    beepSound( fH, 125);beepSound( fHS, 250);
    delay(250);
    beepSound( aS, 250);beepSound( dHS, 500);beepSound( dH, 250);beepSound( cHS, 250);beepSound( cH, 125);
    beepSound( b, 125);beepSound( cH, 250);
    delay(250);
    beepSound( f, 125);beepSound( gS, 500);beepSound( f, 375);beepSound( a, 125);beepSound( cH, 500);
    beepSound( a, 375);beepSound( cH, 125);beepSound( eH, 1000);beepSound( aH, 500);beepSound( a, 350);
    beepSound( a, 150);beepSound( aH, 500);beepSound( gHS, 250);beepSound( gH, 250);beepSound( fHS, 125);
    beepSound( fH, 125);beepSound( fHS, 250);
    delay(50);
    beepSound( aS, 250);beepSound( dHS, 500);beepSound( dH, 250);beepSound( cHS, 250);beepSound( cH, 125);
    beepSound( b, 125);beepSound( cH, 250);
    delay(250);
    beepSound( f, 250);beepSound( gS, 500);beepSound( f, 375);beepSound( cH, 125);beepSound( a, 500);
    beepSound( f, 375);beepSound( c, 125);beepSound( a, 1000);
}

// 소멸자
PiezoClass::~PiezoClass()
{
    softToneStop(mPinNum);
}

