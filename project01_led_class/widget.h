#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "GPIO_PWM_API.h"

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
    LED* LedPin[4];

public slots:
    void led1OnOff();
    void led2OnOff();
    void led3OnOff();
    void led4OnOff();
};
#endif // WIDGET_H
