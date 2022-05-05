#include "widget.h"
#include "ui_widget.h"
#include <wiringPi.h>
//void (*fp[4])(void) = {sw1Isr, sw2Isr, sw3Isr, sw4Isr};

Ui::Widget *pui;
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pui = ui;
}

void Widget::Toggle_LED1(int flag)
{
    if(flag == HIGH)
        ui->led1->setEnabled(true);
    else
        ui->led1->setEnabled(false);
}

void Widget::Toggle_LED2(int flag)
{
    if(flag == HIGH)
        ui->led2->setEnabled(true);
    else
        ui->led2->setEnabled(false);
}

void Widget::Toggle_LED3(int flag)
{
    if(flag == HIGH)
        ui->led3->setEnabled(true);
    else
        ui->led3->setEnabled(false);
}

void Widget::Toggle_LED4(int flag)
{
    if(flag == HIGH)
        ui->led4->setEnabled(true);
    else
        ui->led4->setEnabled(false);
}

Widget::~Widget()
{
    for(int i=0; i<4; i++) {
        delete [] aLed[i];
        delete [] aSw[i];
    }
    delete ui;
}

