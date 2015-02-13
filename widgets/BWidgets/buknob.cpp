#include "buknob.h"
#include <QRect>
#include <QPainter>
#include <QBrush>
#include <QLabel>
#include <iostream>
#define PI 3.14159265

BuKnob::BuKnob(QWidget *parent) :
    QWidget(parent)
{
	setMinimumSize(34,34);
	setMaximumSize(34,34);
	angle = -90;
}

void BuKnob::paintEvent(QPaintEvent * e) {
	QRectF rectangle(2.0, 2.0, 30.0, 30.0);
	QPainter painter(this);
	painter.setPen(QPen(QColor(223,223,223), 2, Qt::SolidLine, Qt::RoundCap,
				    Qt::RoundJoin));
	painter.setBrush(QBrush(QColor(47,47,47)));
	painter.setRenderHint( QPainter::Antialiasing );
	painter.drawEllipse(rectangle);
	int x = (int) (17 + 15*std::cos(angle * PI/180.0));
	int y = (int) (17 + 15*std::sin(angle * PI/180.0));
	painter.drawLine(17,17,x,y);
}

void BuKnob::setAngle(int degrees) {
	angle = degrees - 90;
	update();
}
