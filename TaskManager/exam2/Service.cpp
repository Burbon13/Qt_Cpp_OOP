#include "Service.h"

#include <string>
#include <algorithm>

std::vector<Task>& Service::get_sorted()
{
	std::vector<Task> &v = repo.get_all();
	std::sort(v.begin(), v.end(), [](Task &t1, Task &t2) {
		return t1.get_stare() > t2.get_stare();
	});

	return v;
}

void Service::add(const int & id, const std::string & descriere, const std::vector<std::string>& programatori, const std::string & stare)
{
	if (id < 1)
		throw std::exception("Id-ul trebuie sa fie intreg pozitiv");
	if (descriere.size() == 0)
		throw std::exception("Descrierea trebuie sa nu fie vida");
	if (programatori.size() == 0)
		throw std::exception("Trebuie sa avem programatori");
	if (stare != std::string("open") && stare != std::string("closed") && stare != std::string("inprogress"))
		throw std::exception("Stare invalida");

	repo.add(Task{ id,descriere,programatori,stare });
	update_all();
}

std::vector<Task> Service::get_by_name(const std::string & name)
{
	std::vector<Task> &aux = repo.get_all();
	std::vector<Task> to_return;

	for (auto& i : aux)
	{
		for (auto &j : i.get_programatori())
				if(j.find(name) != std::string::npos)
					to_return.push_back(i);
	}

	return to_return;
}

std::vector<Task> Service::get_by_stare(const std::string & stare)
{
	std::vector<Task> &aux = repo.get_all();
	std::vector<Task> to_return;

	for (auto& i : aux)
	{
		if (i.get_stare() == stare)
			to_return.push_back(i);
	}

	return to_return;
}

void Service::set_stare(const int & id, const std::string & stare)
{
	repo.update(id, stare);
	update_all();
}

Service::~Service()
{
}
