#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_xh254zhy.h"

#include <QTableView>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

#include "service.h"
#include "my_model.h"

class xh254zhy : public QMainWindow
{
	Q_OBJECT

private:
	Ui::xh254zhyClass ui;
	service &serv;

	void update_window();
	void setup_window();

	//---
	void add_action();
	void export_action();
	void delete_action();
	///
	void connect_signals();
	void get_what_clicked(const QModelIndex &index);
public:
	xh254zhy(service & serv) : serv{ serv } {
		setup_window();
	};
	my_model *model;
	QTableView *table_view;
	QPushButton *add_button;
	QPushButton *del_button;
	QPushButton *export_button;
	//line edit for adding flights
	QLineEdit *id_le;
	QLineEdit *time_le;
	QLineEdit *nrp_le;
	QLineEdit *start_le;
	QLineEdit *end_le;
	//----
	QLabel *l1;
	QLabel *l2;
	QLabel *l3;
	QLabel *l4;
	QLabel *l5;

	//---ptr export
	QLabel *l6;
	QLineEdit *exp_le;
	//---

	//----layouts
	QHBoxLayout *main_layout;
	QVBoxLayout *left_layout;
	//----main widget
	QWidget *main_widget;
};
