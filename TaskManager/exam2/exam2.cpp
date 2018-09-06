#include "exam2.h"
#include <QMessageBox>

void exam2::setup()
{
	l1 = new QLabel("Id");
	l2 = new QLabel("Descriere");
	l3 = new QLabel("Programatori");
	l4 = new QLabel("Stare");

	add_button = new QPushButton("Adauga");

	id_le = new QLineEdit();
	descriere_le = new QLineEdit();
	p1_le = new QLineEdit();
	p2_le = new QLineEdit();
	p3_le = new QLineEdit();
	p4_le = new QLineEdit();
	stare_le = new QLineEdit();


	//table = new QTableView();
	//model = new my_model(serv);
	//table->setModel(model);
	table_wdg = new QTableWidget();


	//serv.add_observer(model);

	main_layout = new QHBoxLayout();
	left_layout = new QVBoxLayout(); 

	main_layout->addWidget(table_wdg);

	left_layout->addWidget(l1);
	left_layout->addWidget(id_le);
	left_layout->addWidget(l2);
	left_layout->addWidget(descriere_le);
	left_layout->addWidget(l3);
	left_layout->addWidget(p1_le);
	left_layout->addWidget(p2_le);
	left_layout->addWidget(p3_le);
	left_layout->addWidget(p4_le);
	left_layout->addWidget(l4);
	left_layout->addWidget(stare_le);
	left_layout->addWidget(add_button);

	search_label = new QLabel("Search");
	search_le = new QLineEdit();

	left_layout->addWidget(search_label);
	left_layout->addWidget(search_le);


	main_layout->addLayout(left_layout);

	central = new QWidget();
	central->setLayout(main_layout);
	connect_signals();
	update_me();
	this->setCentralWidget(central);
}

void exam2::add_task()
{
	qDebug("clocked");

	int id;
	std::string descriere;
	std::string aux;
	std::vector<std::string> programatori;
	std::string stare;

	id = id_le->text().toInt();
	descriere = descriere_le->text().toStdString();

	aux = p1_le->text().toStdString();
	if (aux.size())
		programatori.push_back(aux);

	aux = p2_le->text().toStdString();
	if (aux.size())
		programatori.push_back(aux);

	aux = p3_le->text().toStdString();
	if (aux.size())
		programatori.push_back(aux);

	aux = p4_le->text().toStdString();
	if (aux.size())
		programatori.push_back(aux);

	stare = stare_le->text().toStdString();

	try
	{
		serv.add(id, descriere, programatori, stare);
	}
	catch (std::exception& err)
	{
		QMessageBox msg;
		msg.setText(QString::fromStdString(err.what()));
		msg.exec();
	}
}

void exam2::search_event()
{
	std::string name = search_le->text().toStdString();

	std::vector<Task> v = serv.get_by_name(name);

	table_wdg->clear();
	table_wdg->setRowCount(v.size());
	table_wdg->setColumnCount(4);

	int ii = 0;
	int ha;
	std::string vai;
	for (auto & i : v)
	{
		QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(i.get_id()));
		table_wdg->setItem(ii, 0, newItem);

		QTableWidgetItem *newItem2 = new QTableWidgetItem(QString::fromStdString(i.get_descriere()));
		table_wdg->setItem(ii, 1, newItem2);

		QTableWidgetItem *newItem3 = new QTableWidgetItem(QString::number(i.get_programatori().size()));
		table_wdg->setItem(ii, 2, newItem3);

		QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::fromStdString(i.get_stare()));
		table_wdg->setItem(ii, 3, newItem4);

		ii++;
	}
}

void exam2::refresh_table()
{
	std::vector<Task> v = serv.get_sorted();
	
	table_wdg->clear();
	table_wdg->setRowCount(v.size());
	table_wdg->setColumnCount(4);

	int ii = 0;
	int ha;
	std::string vai;
	for (auto & i : v)
	{
		QTableWidgetItem *newItem = new QTableWidgetItem(QString::number(i.get_id()));
		table_wdg->setItem(ii, 0, newItem);

		QTableWidgetItem *newItem2 = new QTableWidgetItem(QString::fromStdString(i.get_descriere()));
		table_wdg->setItem(ii, 1, newItem2);

		QTableWidgetItem *newItem3 = new QTableWidgetItem(QString::number(i.get_programatori().size()));
		table_wdg->setItem(ii, 2, newItem3);

		QTableWidgetItem *newItem4 = new QTableWidgetItem(QString::fromStdString(i.get_stare()));
		table_wdg->setItem(ii, 3, newItem4);

		ii++;
	}
}

void exam2::update_me()
{
	refresh_table();
}

void exam2::connect_signals()
{
	connect(add_button, &QPushButton::clicked, this, &exam2::add_task);
	connect(search_le, &QLineEdit::textChanged, this, &exam2::search_event);
}
