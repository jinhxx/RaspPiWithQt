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
    PiezoClass* piezo;
    PiezoClass* starwars;

public slots:
    void btnChange_mario();
    void btnChange_starwars();
};
#endif // WIDGET_H
