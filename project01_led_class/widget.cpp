#include "widget.h"
#include "ui_widget.h"
#include <wiringPi.h>

int ledPin[4] = {23, 24, 25, 1};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    wiringPiSetupGpio();

    for (int i=0; i<4; i++)
        LedPin[i] = new LED(ledPin[i]);


    connect(ui->checkBox_1, &QCheckBox::clicked, this, &Widget::led1OnOff);
    connect(ui->checkBox_2, &QCheckBox::clicked, this, &Widget::led2OnOff);
    connect(ui->checkBox_3, &QCheckBox::clicked, this, &Widget::led3OnOff);
    connect(ui->checkBox_4, &QCheckBox::clicked, this, &Widget::led4OnOff);
}

void Widget::led1OnOff()
{
    if(ui->checkBox_1->checkState())
    {
        LedPin[0]->on();
        ui->label_1->setEnabled(true);
    }
    else
    {
        LedPin[0]->off();
        ui->label_1->setEnabled(false);
    }
}

void Widget::led2OnOff()
{
    if(ui->checkBox_2->checkState())
    {
        LedPin[1]->on();
        ui->label_2->setEnabled(true);
    }
    else
    {
        LedPin[1]->off();
        ui->label_2->setEnabled(false);
    }
}

void Widget::led3OnOff()
{
    if(ui->checkBox_3->checkState())
    {
        LedPin[2]->on();
        ui->label_3->setEnabled(true);
    }
    else
    {
        LedPin[2]->off();
        ui->label_3->setEnabled(false);
    }
}

void Widget::led4OnOff()
{
    if(ui->checkBox_4->checkState())
    {
        LedPin[3]->on();
        ui->label_4->setEnabled(true);
    }
    else
    {
        LedPin[3]->off();
        ui->label_4->setEnabled(false);
    }
}

Widget::~Widget()
{
//    delete [] LedPin[4];
    delete LedPin[0];
    delete LedPin[1];
    delete LedPin[2];
    delete LedPin[3];
    delete ui;
}

