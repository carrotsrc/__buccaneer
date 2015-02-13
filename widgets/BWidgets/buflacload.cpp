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
	frame->setFrameStyle(QFrame::Panel|QFrame::Sunken);
	frame->setLayout(layout);
	frame->setStyleSheet("background-color: #0b1c26;");
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

void BuFlacLoad::dragEnterEvent(QDragEnterEvent *e) {
    e->acceptProposedAction();
    emit changed(e->mimeData());
}

void BuFlacLoad::dragMoveEvent(QDragMoveEvent *e) {
    e->acceptProposedAction();
}

void BuFlacLoad::dropEvent(QDropEvent *e) {
     const QMimeData *mimeData = e->mimeData();
     if (mimeData->hasText()) {
	     led->setText("Loading...");
	 //led->setText(mimeData->text());
	 //setTextFormat(Qt::PlainText);
     } else {
	 led->setText(tr("Cannot display data"));
     }
     e->acceptProposedAction();
}

void BuFlacLoad::dragLeaveEvent(QDragLeaveEvent *e) {
    e->accept();
}


