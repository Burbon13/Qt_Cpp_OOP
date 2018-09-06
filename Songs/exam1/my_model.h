#pragma once

#include <QAbstractTableModel>
#include "service.h"

class my_model : public QAbstractTableModel
{
private:
	service & serv;
public:
	my_model(service &serv) : serv{ serv } {};

	virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;

	virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	void set_songs();

	~my_model();
};

