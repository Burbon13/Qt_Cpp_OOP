#pragma once

#include <QtWidgets/QMainWindow>
#include <QObject>
#include "observer.h"
#include "Service.h"
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>

class outsider: public QObject,  public Observer
{
	Q_OBJECT
private:
	Service & serv;
	std::string stare;
	void setup();
	void move_to_open();
	void move_to_closed();
	void move_to_inprogess();
public:
	outsider(Service &serv, std::string stare) : serv{ serv }, stare{ stare } {
		setup();
	};
	
	QWidget *central;
	QVBoxLayout *layout;
	QListWidget *list;
	QPushButton* open_btn;
	QPushButton* close_btn;
	QPushButton* progress_btn;

	virtual void update_me() override;

	~outsider();
};

