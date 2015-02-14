#include "buecho.h"
using namespace RackoonIO;
#include <QImage>

BuEcho::BuEcho(QWidget *parent) :
    QWidget(parent)
{
	mainLayout = new QHBoxLayout(this);
	QFrame *frame = new QFrame(this);
	QFrame *topFrame = new QFrame(this);
	QFrame *bottomFrame = new QFrame(this);

	QVBoxLayout *frameLayout = new QVBoxLayout();
	QHBoxLayout *topLayout = new QHBoxLayout();
	QHBoxLayout *bottomLayout = new QHBoxLayout();

	QFont f("Luxi Sans", 10, QFont::Bold);

	QLabel *labelTitle = new QLabel(this);
	labelUnitName = new QLabel(this);
	labelState = new QLabel(this);
	labelState->setText("Decay");
	labelState->setAlignment(Qt::AlignCenter);
	topFrame->setMaximumHeight(25);
	topFrame->setLayout(topLayout);

	knob = new BuKnob(this);

	bottomFrame->setLayout(bottomLayout);

	labelTitle->setText("Pirate Echo");
	labelTitle->setFont(f);

	topLayout->setAlignment(Qt::AlignTop);
	topLayout->addWidget(labelTitle);
	topLayout->addWidget(labelUnitName);
	topLayout->setAlignment(labelUnitName, Qt::AlignRight);

	QVBoxLayout *decayArray = new QVBoxLayout();
	decayArray->setAlignment(Qt::AlignRight);
	decayArray->addWidget(labelState);
	decayArray->addWidget(knob);

	bottomLayout->setAlignment(Qt::AlignLeft);
	bottomLayout->addLayout(decayArray);

	frameLayout->addWidget(topFrame);
	frameLayout->addWidget(bottomFrame);

	frame->setMaximumHeight(100);
	frame->setMinimumHeight(100);
	frame->setLayout(frameLayout);

	//frame->setStyleSheet("background-color: #45454F;");
	frame->setStyleSheet("background-image: url('res/dark_fish_skin.png');");
	frame->setFrameStyle(QFrame::Panel|QFrame::Raised);
	frame->setLineWidth(3);

	mainLayout->addWidget(frame);
	setLayout(mainLayout);

}

void BuEcho::linkUnit(RackUnit *unit) {
	if(unit->getRuType() != "RuEcho")
		return;
	ruUnit = static_cast<RuEcho*>(unit);
	ruUnit->onDecayChangeCallback(std::bind(&BuEcho::onDecayChange, this, std::placeholders::_1));
	labelUnitName->setText(QString::fromStdString(unit->getName()));
}

void BuEcho::setEventLoop(RackoonIO::EventLoop *loop) {
	eventLoop = loop;
}

void BuEcho::onDecayChange(int value) {
	decayValue = value;
	int angle = 0;
	if(value > 64) {
		angle = (int)(2*(value-64));
	} else
	if(value < 64) {
		angle = (int)-(2*(64-value));
	}
	knob->setAngle(angle);
	//QMetaObject::invokeMethod(this, "decayChanged", Qt::QueuedConnection, Q_ARG(int, value));
}

void BuEcho::paintEvent(QPaintEvent *e) {

}
