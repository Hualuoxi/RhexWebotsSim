#pragma once
#ifndef HEX_USER_H
#define HEX_USER_H
#include <webots/Robot.hpp>
#include <webots/motor.hpp>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QTimerEvent>
#include <QCoreApplication>
#include <QTime>

using namespace webots;
using namespace std;

class Hex_user : public QThread
{
	Q_OBJECT

public:
	Hex_user(QObject* parent = NULL);
	~Hex_user();

public:
	Robot* robot;
	int timeStep;
	Motor* motor[7] = {NULL};
	QTimer* timerDataProcess = NULL;
	QTimer* timerSendProcess = NULL;
private:
	void Init_Robot();
protected:
	void run();

public slots:
	void Data_Process();
	void Send_Process();
};

#endif