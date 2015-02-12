#include "buflacload.h"
using namespace RackoonIO;
#include "events/ShellEvents.h"
#include <QVBoxLayout>
#include <QPixmap>

BuFlacLoad::BuFlacLoad(QWidget *parent) :
    QWidget(parent)
{
	QVBoxLayout *layout = new QVBoxLayout(this);
	QVBoxLayout *mainLayout = new QVBoxLayout(this);


	setMaximumSize(300,75);

	labelFilename = new QLabel(this);
	labelFilename->setText(tr("Unloaded"));
	labelFilename->setAlignment(Qt::AlignCenter);

	led = new QLabel(this);
	led->setText("Loading...");
	layout->addWidget(labelFilename);
	layout->addWidget(led);

	frame = new QFrame(this);
	frame->setFrameStyle(QFrame::Sunken);
	frame->setLayout(layout);
	frame->setAutoFillBackground(true);
	frame->setMinimumHeight(75);

	mainLayout->addWidget(frame);
	setLayout(mainLayout);

	setAcceptDrops(true);
	setAutoFillBackground(true);

}

void BuFlacLoad::linkUnit(RackUnit *unit) {
	if(unit->getRuType() != "RuFlacLoad")
		return;
	eventLoop->addEventListener(FlacLoadInit, std::bind(&BuFlacLoad::unitOnInit, this, std::placeholders::_1));
	ruUnit = static_cast<RuFlacLoad*>(unit);
}

void BuFlacLoad::unitOnInit(std::shared_ptr<RackoonIO::EventMessage> msg) {
	std::string name = ruUnit->getFilename();

	labelFilename->setText(QString::fromStdString(ruUnit->getFilename()));
	led->setText("Ready");
	cout << _FlacLoadInit(msg)->numFrames << endl;
}

void BuFlacLoad::setEventLoop(RackoonIO::EventLoop *loop) {
	eventLoop = loop;
}

