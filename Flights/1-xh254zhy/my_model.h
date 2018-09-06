#pragma once

#include <QAbstractTableModel>
#include "service.h"

class my_model : public QAbstractTableModel
{
private:
	service & serv;

	QString get_data(int i, int j) const;
	int color_case(int i) const;
public:
	my_model(service &serv) : serv{ serv } {};

	void set_flights()
	{
		QModelIndex top_left = createIndex(0, 0);
		QModelIndex bottom_right = createIndex(rowCount(), columnCount());
		emit layoutChanged();
		emit dataChanged(top_left, bottom_right);
	}

	/*
	Returns number of rows
	*/
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;

	/*
	Return number of columns
	*/
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

	~my_model();
};

