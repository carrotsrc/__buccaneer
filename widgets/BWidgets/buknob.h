#ifndef BUKNOB_H
#define BUKNOB_H

#include <QWidget>
#include <QVBoxLayout>
class BuKnob : public QWidget
{
    Q_OBJECT

	double angle;
	QVBoxLayout *layout;
public:
    BuKnob(QWidget *parent = 0);
    void setAngle(int);

public slots:
    void paintEvent(QPaintEvent *);
};

#endif
