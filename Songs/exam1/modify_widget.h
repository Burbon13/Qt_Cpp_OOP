#pragma once

#include <QWidget>
#include <QPainter>
#include <memory>

class modify_widget : public QWidget
{
	Q_OBJECT
private:
	int nr;
	virtual void paintEvent(QPaintEvent *event) override
	{
		qDebug("ma redeseneees");
		QPainter pnt{ this };
		for (int i = 1; i <= nr; i++)
		{
			pnt.drawEllipse(QPoint(0, 0), 3*i, i);
		}
	}
public:
	modify_widget(int nr) : nr{ nr } {
	};

	void pain_songs(int nr)
	{
		this->nr = nr;
		this->repaint();
	}

	~modify_widget() = default;
};

