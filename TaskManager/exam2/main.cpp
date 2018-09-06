#include "exam2.h"
#include <QtWidgets/QApplication>

#include "test.h"
#include "outsider.h"

int main(int argc, char *argv[])
{
	test_all();

	Repo repo{ "task.txt" };
	Service serv{ repo };

	QApplication a(argc, argv);


	outsider *open = new outsider(serv, "open");
	outsider *closed = new outsider(serv, "closed");
	outsider *inprogress = new outsider(serv, "inprogress");

	exam2 w(serv);

	serv.add_observer(&w);
	serv.add_observer(open);
	serv.add_observer(closed);
	serv.add_observer(inprogress);

	w.show();
	return a.exec();
}
