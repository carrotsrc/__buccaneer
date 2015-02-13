#include "buecho.h"
using namespace RackoonIO;

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

	topFrame->setMaximumHeight(25);
	topFrame->setLayout(topLayout);

	bottomFrame->setLayout(bottomLayout);

	labelTitle->setText("Pirate Echo");
	labelTitle->setFont(f);

	topLayout->setAlignment(Qt::AlignTop);
	topLayout->addWidget(labelTitle);
	topLayout->addWidget(labelUnitName);
	topLayout->setAlignment(labelUnitName, Qt::AlignRight);

	labelState->setText("Running");
	bottomLayout->addWidget(labelState);
	bottomLayout->setAlignment(Qt::AlignTop);

	frameLayout->addWidget(topFrame);
	frameLayout->addWidget(bottomFrame);

	frame->setMaximumHeight(100);
	frame->setMinimumHeight(100);
	frame->setLayout(frameLayout);

	frame->setStyleSheet("background-color: #45454F;");
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
	cout << value << endl;
}
