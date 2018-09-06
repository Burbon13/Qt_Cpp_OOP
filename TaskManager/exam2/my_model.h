#pragma once

#include "Service.h"
#include <QAbstractTableModel>
#include "observer.h"

class my_model: public QAbstractTableModel, public Observer
{
private:
	Service & serv;
public:
	my_model(Service &serv) : serv{ serv } {};

	virtual int rowCount(const QModelIndex& parent = QModelIndex()) const override;

	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	void set_tasks();

	virtual void update_me() override;
	
	~my_model();
};

