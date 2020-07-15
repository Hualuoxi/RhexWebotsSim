#include "Hex_user.h"
Hex_user::Hex_user(QObject* parent)
{
    // create the Robot instance.
    robot = new Robot();
    // get the time step of the current world.
    timeStep = (int)robot->getBasicTimeStep();

    QString motor_name;
    for (int i = 1; i < 7; i++)
    {
        motor_name = "leg_motor" + QString::number(i);
        qDebug() << motor_name;
        motor[i] = robot->getMotor(motor_name.toStdString());
        motor[i]->setPosition(INFINITY);
    }
    motor_name.clear();
}

Hex_user::~Hex_user()
{
    delete robot;
}

void Hex_user::Init_Robot()
{

}

/**
 * @brief 子线程
 */
void Hex_user::run()
{
    
    //数据处理线程定时触发
    timerDataProcess = new QTimer();
    timerDataProcess->setInterval(10);
    connect(timerDataProcess, SIGNAL(timeout()), this, SLOT(Data_Process()), Qt::QueuedConnection);
    timerDataProcess->start();

    //数据发送线程定时触发
    timerSendProcess = new QTimer();
    timerSendProcess->setInterval(10);
    connect(timerSendProcess, SIGNAL(timeout()), this, SLOT(Send_Process()), Qt::QueuedConnection);
    timerSendProcess->start();

    QThread::exec();
}

void Hex_user::Data_Process()
{
    qDebug() << "Data_Process is running";
}

void Hex_user::Send_Process()
{
    qDebug() << "Send_Process is running";
    if (robot->step(timeStep) != -1)
    {
        for (int i = 1; i < 7; i++)
        {
            motor[i]->setVelocity(1.0);
        }
    };
}