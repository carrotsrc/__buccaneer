#include "buecho.h"
using namespace RackoonIO;

BuEcho::BuEcho(QWidget *parent) :
    QWidget(parent)
{
	mainLayout = new QHBoxLayout(this);
	QFrame *frame = new QFrame(this);
	frame->setMaximumHeight(150);
	frame->setMinimumHeight(150);
	QHBoxLayout *frameLayout = new QHBoxLayout(frame);
	frame->setLayout(frameLayout);

	frame->setStyleSheet("background-color: #45454F;");
	frame->setFrameStyle(QFrame::Panel|QFrame::Raised);

	mainLayout->addWidget(frame);
	setLayout(mainLayout);

}

void BuEcho::linkUnit(RackUnit *unit) {
	if(unit->getRuType() != "RuEcho")
		return;
	ruUnit = static_cast<RuEcho*>(unit);
}

void BuEcho::setEventLoop(RackoonIO::EventLoop *loop) {
	eventLoop = loop;
}
