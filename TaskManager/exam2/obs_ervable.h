#pragma once

#include "observer.h"
#include <vector>

class Observable
{
private:
	std::vector<Observer *> observers;
public:
	void add_observer(Observer * obs)
	{
		observers.push_back(obs);
	}

	void update_all()
	{
		for (auto& i : observers)
			i->update_me();
	}
};