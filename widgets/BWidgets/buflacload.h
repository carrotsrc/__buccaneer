#ifndef BUFLACLOAD_H
#define BUFLACLOAD_H

#include <QWidget>
#include <QFrame>

#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QLabel>

#include "units/RuFlacLoad.h"

class BuFlacLoad : public QWidget
{
    Q_OBJECT

public:
    BuFlacLoad(QWidget *parent = 0);
    void linkUnit(RackoonIO::RackUnit*);

    void unitOnInit(std::shared_ptr<RackoonIO::EventMessage>);
    void setEventLoop(RackoonIO::EventLoop*);

private:
    RackoonIO::EventLoop *eventLoop;
    RuFlacLoad *ruUnit;

    QFrame *frame;
    QLabel *led;

    QLabel *labelFilename;
protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dragLeaveEvent(QDragLeaveEvent *e);
    void dragMoveEvent(QDragMoveEvent *e);
    void dropEvent(QDropEvent *e);

signals:
    void changed(const QMimeData *mimeData = 0);
};

#endif
