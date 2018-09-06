#include "my_model.h"

int my_model::rowCount(const QModelIndex & parent) const
{
	return serv.get_sorted().size();
}

int my_model::columnCount(const QModelIndex & parent) const
{
	return 4;
}

QVariant my_model::data(const QModelIndex & index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		int row = index.row();
		int column = index.column();

		int ha;
		std::string vai;
		switch (column)
		{
		case 0:
			ha = serv.get_sorted()[row].get_id();
			return QString::number(ha);
		case 1:
			vai = serv.get_sorted()[row].get_descriere();
			return QString::fromStdString(vai);
		case 2:
			ha = serv.get_sorted()[row].get_programatori().size();
			return QString::number(ha);
		default:
			vai = serv.get_sorted()[row].get_stare();
			return QString::fromStdString(vai);
		}
	}
	return QVariant();
}

void my_model::set_tasks()
{
	QModelIndex top_left = createIndex(0, 0);
	QModelIndex bottom_right = createIndex(rowCount(), columnCount());
	emit layoutChanged();
	emit dataChanged(top_left, bottom_right);
}

void my_model::update_me()
{
	set_tasks();
}

my_model::~my_model()
{
}
