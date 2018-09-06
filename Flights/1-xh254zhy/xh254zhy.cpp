#include "xh254zhy.h"

#include <QMessageBox>
#include <qDebug>

void xh254zhy::update_window()
{
}

void xh254zhy::setup_window()
{
	model = new my_model{ serv };
	table_view = new QTableView{};
	table_view->setModel(model);

	add_button = new QPushButton{"Add"};
	del_button = new QPushButton{"Delete"};
	export_button = new QPushButton{"Export"};
	//line edit for adding flights
	id_le = new QLineEdit{};
	time_le = new QLineEdit{};
	nrp_le = new QLineEdit{};
	start_le = new QLineEdit{};
	end_le = new QLineEdit{};

	l1 = new QLabel{"Id"};
	l2 = new QLabel{"Time Travel"};
	l3 = new QLabel{"Nr places"};
	l4 = new QLabel{"Starting city"};
	l5 = new QLabel{"End city"};

	//----layouts
	main_layout = new QHBoxLayout{};
	left_layout = new QVBoxLayout{};

	//----
	main_widget = new QWidget();

	main_layout->addWidget(table_view);

	left_layout->addWidget(l1);
	left_layout->addWidget(id_le);
	left_layout->addWidget(l2);
	left_layout->addWidget(time_le);
	left_layout->addWidget(l3);
	left_layout->addWidget(nrp_le);
	left_layout->addWidget(l4);
	left_layout->addWidget(start_le);
	left_layout->addWidget(l5);
	left_layout->addWidget(end_le);
	left_layout->addWidget(add_button);
	left_layout->addWidget(del_button);
	left_layout->addWidget(export_button);

	main_layout->addLayout(left_layout);
	main_widget->setLayout(main_layout);

	connect_signals();
	
	this->setCentralWidget(main_widget);
}

void xh254zhy::add_action()
{
	int id = id_le->text().toInt();
	int time = time_le->text().toInt();
	int nr_pl = nrp_le->text().toInt();
	std::string start = start_le->text().toStdString();
	std::string end = end_le->text().toStdString();

	try
	{
		serv.add(id, time, nr_pl, start, end);
		model->set_flights();

	}
	catch (service_exception &se)
	{
		QMessageBox msg;
		msg.setText(QString::fromStdString(se.get_error()));
		msg.exec();
	}
}

void xh254zhy::export_action()
{
	
}

void xh254zhy::delete_action()
{
	qDebug("delet");
}

void xh254zhy::connect_signals()
{
	connect(add_button, &QPushButton::clicked, this, &xh254zhy::add_action);
	connect(export_button, &QPushButton::clicked, this, &xh254zhy::export_action);
	connect(del_button, &QPushButton::clicked, this, &xh254zhy::delete_action);
	connect(table_view, &QAbstractItemView::clicked, this, &xh254zhy::get_what_clicked);
}

void xh254zhy::get_what_clicked(const QModelIndex & index)
{
	int row = index.row();
	int column = index.column();

	qDebug() << row << ' ' << column << '\n';
	QModelIndex ind =  model->index(row, 0, QModelIndex());
	//qDebug() << model->data(index).toString();

	int id = model->data(ind).toString().toInt();

	flight f = serv.get_f(id);

	id_le->setText(QString::number(f.get_id_flight()));
	time_le->setText(QString::number(f.get_time_travel()));
	nrp_le->setText(QString::number(f.get_nr_places()));
	start_le->setText(QString::fromStdString(f.get_start_city()));
	end_le->setText(QString::fromStdString(f.get_end_city()));
}
