#ifndef BULEVELS_H
#define BULEVELS_H

#include <QWidget>
#include <QSlider>
#include <QFrame>
#include <QGridLayout>
#include "buknob.h"
#include "units/RuLevels.h"

using namespace RackoonIO;
class BuLevels : public QWidget
{
	Q_OBJECT
private:
	BuKnob *channelGain;
	QSlider *channelFader;
	QFrame *frame;
	QGridLayout *widgetLayout;
	RuLevels *ruUnit;
	RackoonIO::EventLoop *eventLoop;

	void gainChange(int);
	void fadeChange(int);
public:
	explicit BuLevels(QWidget *parent = 0);
	void linkUnit(RackoonIO::RackUnit*);
	void setEventLoop(RackoonIO::EventLoop*);
signals:

public slots:

};

#endif // BULEVELS_H
