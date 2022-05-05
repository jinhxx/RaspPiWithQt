#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <GPIO_PWM_API.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;

public:
    GPIO_LED* aLed[4];
    GPIO_SWITCH* aSw[4];

public:
    void Toggle_LED1(int flag);
    void Toggle_LED2(int flag);
    void Toggle_LED3(int flag);
    void Toggle_LED4(int flag);
};
#endif // WIDGET_H
