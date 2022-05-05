#include "widget.h"
#include <wiringPi.h>
#include <GPIO_PWM_API.h>
#include <QApplication>

void sw1Isr(void);
void sw2Isr(void);
void sw3Isr(void);
void sw4Isr(void);

const int ledPin[4] = {23, 24, 25, 1};
const int swPin[4] = {4, 17, 27, 22};
int swFlag[4] = {0,};
void (*fp[4])(void) = {sw1Isr, sw2Isr, sw3Isr, sw4Isr};
Widget *pw;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    pw = &w;

    for (int i=0; i<4; i++)
    {
        w.aLed[i] = new GPIO_LED(ledPin[i]);
        w.aSw[i] = new GPIO_SWITCH(swPin[i], INT_EDGE_RISING, fp[i]);

    }
//    w.aSw[0] = new GPIO_SWITCH(swPin[0], INT_EDGE_RISING, sw1Isr);

    w.show();
    return a.exec();
}

void sw1Isr(void) {
    if(swFlag[0] == 0) {
        pw->aLed[0]->ledWrite(HIGH);
        pw->Toggle_LED1(HIGH);
        swFlag[0] = 1;
    }
    else {
        pw->aLed[0]->ledWrite(LOW);
        pw->Toggle_LED1(LOW);
        swFlag[0] = 0;
    }
}

void sw2Isr(void) {
    if(swFlag[1] == 0) {
        pw->aLed[1]->ledWrite(HIGH);
        pw->Toggle_LED2(HIGH);
        swFlag[1] = 1;
    }
    else {
        pw->aLed[1]->ledWrite(LOW);
        pw->Toggle_LED2(LOW);
        swFlag[1] = 0;
    }
}

void sw3Isr(void) {
    if(swFlag[2] == 0) {
        pw->aLed[2]->ledWrite(HIGH);
        pw->Toggle_LED3(HIGH);
        swFlag[2] = 1;
    }
    else {
        pw->aLed[2]->ledWrite(LOW);
        pw->Toggle_LED3(LOW);
        swFlag[2] = 0;
    }
}

void sw4Isr(void) {
    if(swFlag[3] == 0) {
        pw->aLed[3]->ledWrite(HIGH);
        pw->Toggle_LED4(HIGH);
        swFlag[3] = 1;
    }
    else {
        pw->aLed[3]->ledWrite(LOW);
        pw->Toggle_LED4(LOW);
        swFlag[3] = 0;
    }
}
