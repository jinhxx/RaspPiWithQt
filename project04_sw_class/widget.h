#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "GPIO_PWM_API.h"
#include "I2C_GPIO_API.h"

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QWidget
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

public:
    Ui::widget *ui;
    GPIO_LED *LED12[2];
    PWM_LED *LED34[2];
    GPIO_SW *SW[4];
    I2C_SHT20 *sht20;
    QPushButton *temp_btn;
    QPushButton *humi_btn;
    GPIO_PIR *PIR;

public slots:
    void chkChanged(bool value);
    void sliderChanged(int value);
    int playButton(bool value);
    void display_temp();
    void display_humi();

//public:
//    void Toggle_PIR();
//    void Toggle_LED1(int flag);
//    void Toggle_LED2(int flag);
//    void Toggle_LED3(int flag);
//    void Toggle_LED4(int flag);
};
#endif // WIDGET_H
