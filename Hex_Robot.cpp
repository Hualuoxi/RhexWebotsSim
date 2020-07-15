#include "Hex_Robot.h"
int main(int argc, char **argv) 
{
	QCoreApplication a(argc, argv);
	Hex_user* rhex=new Hex_user();
	rhex->start();
	return a.exec();
}
