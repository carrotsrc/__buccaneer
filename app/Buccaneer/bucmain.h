#ifndef BUCMAIN_H
#define BUCMAIN_H

#include <QMainWindow>

#include "framework/rack/Rack.h"
#include "factories/RackUnitFactory.h"
#include "factories/EventMessageFactory.h"

namespace Ui {
class BucMain;
}

class BucMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit BucMain(QWidget *parent = 0);
    ~BucMain();



private:
	void initRackoonIO();
    Ui::BucMain *ui;
    RackoonIO::Rack *rack;
    std::map<std::string, RackoonIO::RackUnit*> units;
    std::vector<QWidget*> mainLine;
};

#endif // BUCMAIN_H
