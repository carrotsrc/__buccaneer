#include "bulevels.h"
#include <QLabel>
#include <QHBoxLayout>
BuLevels::BuLevels(QWidget *parent) :
QWidget(parent)
{
	frame = new QFrame();
	frame->setMinimumHeight(75);
	widgetLayout = new QGridLayout();
	frame->setLayout(widgetLayout);
	frame->setStyleSheet("background-image: url('res/micro_carbon.png');");
	frame->setFrameStyle(QFrame::Panel|QFrame::Raised);
	frame->setLineWidth(3);

	QLabel *labelGain = new QLabel("Gain");
	channelGain = new BuKnob();
	channelFader = new QSlider(Qt::Horizontal);
	channelFader->setTickPosition(QSlider::TicksBelow);
	widgetLayout->setAlignment(Qt::AlignLeft);
	widgetLayout->addWidget(labelGain, 0, 0);
	widgetLayout->addWidget(channelGain, 1, 0);

	widgetLayout->addWidget(new QLabel("Channel Fader"), 0, 1);
	widgetLayout->addWidget(channelFader, 1, 1);


	QHBoxLayout *main = new QHBoxLayout(this);
	main->addWidget(frame);
	this->setLayout(main);
}

void BuLevels::linkUnit(RackUnit *unit) {
	if(unit->getRuType() != "RuLevels")
		return;
	ruUnit = static_cast<RuLevels*>(unit);
	ruUnit->cbFadeChange(std::bind(&BuLevels::fadeChange, this, std::placeholders::_1));
	ruUnit->cbGainChange(std::bind(&BuLevels::gainChange, this, std::placeholders::_1));

}

void BuLevels::setEventLoop(RackoonIO::EventLoop *loop) {
	eventLoop = loop;
}

void BuLevels::gainChange(int value) {
	int angle = 0;
	if(value > 64) {
		angle = (int)(2*(value-64));
	} else
	if(value < 64) {
		angle = (int)-(2*(64-value));
	}
	channelGain->setAngle(angle);
}

void BuLevels::fadeChange(int value) {
	cout << "Fade change" << endl;
}
