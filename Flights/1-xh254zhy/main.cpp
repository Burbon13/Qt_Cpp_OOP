#include "xh254zhy.h"
#include <QtWidgets/QApplication>

#include "test.h"

int main(int argc, char *argv[])
{
	
	test_all();
	QApplication a(argc, argv);
	
	repo rep{ "flights.txt" };
	service serv{ rep };
	xh254zhy w{ serv };

	w.show();

	return a.exec();
}
