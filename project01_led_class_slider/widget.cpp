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

    connect(ui->horizontalSlider, QOverload<int>::of(&QSlider::valueChanged), this, &Widget::led1_valueChanged);
    connect(ui->horizontalSlider_2, QOverload<int>::of(&QSlider::valueChanged), this, &Widget::led2_valueChanged);
    connect(ui->checkBox, &QCheckBox::clicked, this, &Widget::led3_valueChanged);
    connect(ui->checkBox_2, &QCheckBox::clicked, this, &Widget::led4_valueChanged);
}

void Widget::led1_valueChanged(int value) {
    LedPin[0]->ledPwmWrite(value);
    ui->horizontalSlider->setValue(value);
}

void Widget::led2_valueChanged(int value) {
    LedPin[1]->ledPwmWrite(value);
    ui->horizontalSlider_2->setValue(value);
}

void Widget::led3_valueChanged()
{
    if(ui->checkBox->checkState())
    {
        LedPin[2]->on();
    }
    else
    {
        LedPin[2]->off();
    }
}

void Widget::led4_valueChanged()
{
    if(ui->checkBox_2->checkState())
    {
        LedPin[3]->on();
    }
    else
    {
        LedPin[3]->off();
    }
}

Widget::~Widget()
{
    delete LedPin[0];
    delete LedPin[1];
    delete LedPin[2];
    delete LedPin[3];
    delete ui;
}

