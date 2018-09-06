#include "outsider.h"
#include <QList>
#include<qdebug.h>

void outsider::setup()
{
	central = new QWidget();

	central->setWindowTitle(QString::fromStdString(stare));

	layout = new QVBoxLayout();
	list = new QListWidget();
	open_btn = new QPushButton("Open");
	close_btn = new QPushButton("Close");
	progress_btn = new QPushButton("In progress");

	layout->addWidget(list);
	layout->addWidget(open_btn);
	layout->addWidget(close_btn);
	layout->addWidget(progress_btn);

	central->setLayout(layout);
	central->show();

	connect(open_btn, &QPushButton::clicked, this, &outsider::move_to_open);
	connect(close_btn, &QPushButton::clicked, this, &outsider::move_to_closed);
	connect(progress_btn, &QPushButton::clicked, this, &outsider::move_to_inprogess);

	update_me();
}

void outsider::move_to_open()
{
	QList<QListWidgetItem*> lst = list->selectedItems();

	for (int i = 0; i < lst.size(); i++)
	{
		QString qst =  lst[i]->text();
		serv.set_stare(qst.toInt(), "open");
	}
}

void outsider::move_to_closed()
{
	QList<QListWidgetItem*> lst = list->selectedItems();

	for (int i = 0; i < lst.size(); i++)
	{
		QString qst = lst[i]->text();
		serv.set_stare(qst.toInt(), "closed");
	}
}

void outsider::move_to_inprogess()
{
	QList<QListWidgetItem*> lst = list->selectedItems();

	for (int i = 0; i < lst.size(); i++)
	{
		QString qst = lst[i]->text();
		serv.set_stare(qst.toInt(), "inprogress");
	}
}

void outsider::update_me()
{
	std::vector<Task> v = serv.get_by_stare(stare);

	list->clear();
	for (auto &i : v)
	{
		QListWidgetItem *itm = new QListWidgetItem();
		itm->setText(QString::number(i.get_id()));
		list->addItem(itm);
	}
}

outsider::~outsider()
{
}
