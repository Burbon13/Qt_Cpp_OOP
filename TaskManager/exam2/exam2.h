#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_exam2.h"
#include "Service.h"

#include "my_model.h"
#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include "observer.h"

class exam2 : public QMainWindow, public Observer
{
	Q_OBJECT
private:
	Ui::exam2Class ui;
	Service &serv;
	void setup();

	void add_task();
	void connect_signals();
	void search_event();
	void refresh_table();
public:
	virtual void update_me() override;

	exam2(Service &serv) : serv{ serv } { setup(); };

	QLabel *l1, *l2, *l3, *l4;
	QPushButton *add_button;

	QLineEdit *id_le;
	QLineEdit *descriere_le;
	QLineEdit *p1_le;
	QLineEdit *p2_le;
	QLineEdit *p3_le;
	QLineEdit *p4_le;
	QLineEdit *stare_le;

	QHBoxLayout *main_layout;
	QVBoxLayout *left_layout;

	my_model *model;
	QTableView *table;

	QWidget *central;

	///serach functionality
	QLabel *search_label;
	QLineEdit *search_le;

	QTableWidget *table_wdg;
};
