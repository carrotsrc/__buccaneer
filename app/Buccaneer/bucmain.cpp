#include "bucmain.h"
#include "ui_bucmain.h"

#include "buflacload.h"
#include <QVBoxLayout>

BucMain::BucMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BucMain)
{
	ui->setupUi(this);
	initRackoonIO();
	rack->start();
	units = rack->getUnits();
	ui->verticalMainlines->setAlignment(Qt::AlignTop);
	std::map<std::string, RackoonIO::RackUnit*>::iterator it;


	for(it = units.begin(); it != units.end(); ++it) {
	    RackoonIO::RackUnit *unit = (*it).second;

	    if(unit->getRuType() == "RuFlacLoad") {
		    BuFlacLoad *bflac = new BuFlacLoad(this);
		    bflac->setEventLoop(rack->getEventLoop());
		    bflac->linkUnit(unit);
		    mainLine.push_back(bflac);
		    ui->verticalMainlines->addWidget(bflac);
	    }
	}



}

BucMain::~BucMain()
{
    delete ui;
}
void BucMain::initRackoonIO() {
	rack = new RackoonIO::Rack();
	std::unique_ptr<RackoonIO::RackUnitGenericFactory> factory(new RackUnitFactory);
	factory->setMessageFactory(new EventMessageFactory);
	rack->setRackUnitFactory(std::move(factory));

	rack->setConfigPath("buccaneer.cfg");
	rack->init();
	rack->initEvents(NUM_EVENTS);




}
