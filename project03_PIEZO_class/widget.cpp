#include "widget.h"
#include "ui_widget.h"

const int piezoPin = 12;

int scale[] = { 659, 659, 0, 659, 0, 523, 659, 0, 784, 0,0,0, 392, 0,0,0, 523, 0,0, 392, 0,0,330 };
int scale_size = sizeof(scale) / sizeof(scale[0]);

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    piezo = new PiezoClass(piezoPin);

//    piezo->playMelody(scale, scale_size);

    connect(ui->playButton_2, &QPushButton::clicked, this, &Widget::btnChange_mario);
    connect(ui->playButton_1, &QPushButton::clicked, this, &Widget::btnChange_starwars);
}

void Widget::btnChange_mario() {
    piezo->playMelody(scale, scale_size);
//    if (ui->playButton_2->text() == "PLAY")
//        ui->playButton_2->setText("STOP");
//    else
//        ui->playButton_2->setText("PLAY");
}

void Widget::btnChange_starwars() {
    piezo->playStarwarsBGM();
}

Widget::~Widget()
{
    delete ui;
}

