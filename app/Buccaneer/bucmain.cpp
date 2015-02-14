#include "bucmain.h"
#include "ui_bucmain.h"

#include "buflacload.h"
#include "buecho.h"
#include "bulevels.h"
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
	ui->verticalRack->setAlignment(Qt::AlignTop);
	ui->verticalRack->setSpacing(5);
	std::map<std::string, RackoonIO::RackUnit*>::iterator it;


	for(it = units.begin(); it != units.end(); ++it) {
		RackoonIO::RackUnit *unit = (*it).second;

		if(unit->getRuType() == "RuFlacLoad") {
			BuFlacLoad *bflac = new BuFlacLoad(this);
			bflac->setEventLoop(rack->getEventLoop());
			bflac->linkUnit(unit);
			mainLine.push_back(bflac);
			ui->verticalMainlines->addWidget(bflac);
		} else
		if(unit->getRuType() == "RuEcho") {
			BuEcho *becho = new BuEcho(this);
			becho->setEventLoop(rack->getEventLoop());
			becho->linkUnit(unit);
			ui->verticalMainlines->addWidget(becho);
		}
		else
		if(unit->getRuType() == "RuLevels") {
		       BuLevels *blevels = new BuLevels(this);
		       blevels->setEventLoop(rack->getEventLoop());
		       blevels->linkUnit(unit);
		       ui->verticalRack->addWidget(blevels);
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
