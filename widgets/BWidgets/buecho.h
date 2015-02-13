#ifndef BUECHO_H
#define BUECHO_H

#include <QWidget>
#include <QHBoxLayout>
#include <QFrame>
#include "units/RuEcho.h"
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
};

#endif
