#ifndef BUECHO_H
#define BUECHO_H

#include <QWidget>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QImage>
#include "units/RuEcho.h"
#include "buknob.h"
class BuEcho : public QWidget
{
    Q_OBJECT


public:
    BuEcho(QWidget *parent = 0);
    void linkUnit(RackoonIO::RackUnit*);
    void setEventLoop(RackoonIO::EventLoop*);
private:
    RuEcho *ruUnit;
    RackoonIO::EventLoop *eventLoop;
    QHBoxLayout *mainLayout;
    QLabel *labelUnitName, *labelState;
    BuKnob *knob;
    int decayValue;

    void onDecayChange(int);

public slots:
    void paintEvent(QPaintEvent *);
};

#endif
