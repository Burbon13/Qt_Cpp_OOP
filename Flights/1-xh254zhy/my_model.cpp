#include "my_model.h"

#include <QFont>
#include <QBrush>

int my_model::rowCount(const QModelIndex & parent) const
{
	return serv.get_ref().size();
}

int my_model::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QString my_model::get_data(int i, int j) const
{
	std::string s;
	switch(j)
	{
	case 0:
		s = std::to_string(serv.get_ref()[i].get_id_flight());
		return QString::fromStdString(s);
	case 1:
		s = std::to_string(serv.get_ref()[i].get_time_travel());
		return QString::fromStdString(s);
	case 2:
		s = std::to_string(serv.get_ref()[i].get_nr_places());
		return QString::fromStdString(s);
	case 3:
		s = serv.get_ref()[i].get_start_city();
		return QString::fromStdString(s);
	default:
		s = serv.get_ref()[i].get_end_city();
		return QString::fromStdString(s);
	}
}

int my_model::color_case(int i) const
{
	int nr = serv.get_ref()[i].get_nr_places();

	if (nr < 10)
		return 0;
	if (nr < 20)
		return 1;
	return 2;
}

QVariant my_model::data(const QModelIndex & index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		int row = index.row();
		int column = index.column();

		return get_data(row, column);
	}
	else if (role == Qt::FontRole)
	{
		//QFont f;
		//f.setColor(Qt::red);
		return QVariant();
	}
	else if (role == Qt::BackgroundRole)
	{
		int row = index.row();
		switch (color_case(row))
		{
		case 0:
			return QBrush(Qt::red);
		case 1:
			return QBrush(Qt::yellow);
		default:
			return QBrush(Qt::green);
		}
	}
	return QVariant();
}

my_model::~my_model()
{
}
