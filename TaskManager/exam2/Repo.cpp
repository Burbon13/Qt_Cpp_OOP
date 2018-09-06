#include "Repo.h"

#include <exception>
#include <fstream>

void Repo::load_file()
{
	std::ifstream f;
	f.open(file_name);
	if (!f.is_open())
	{
		throw std::exception("Nu s-a putut deschide fisierul!");
	}
	//!!!
	int id;
	std::string descriere;
	std::vector<std::string> programatori;
	std::string stare;
	while (f >> id)
	{
		f.get();
		std::getline(f, descriere);
		int cati;
		f >> cati;
		f.get();
		programatori.clear();
		for (int i = 0; i < cati; i++)
		{
			std::string s;
			std::getline(f, s);
			programatori.push_back(s);
		}
		f >> stare;
		tasks.push_back(Task{ id,descriere,programatori,stare });
	}
	f.close();
}

void Repo::save_file()
{
	std::ofstream o;
	o.open(file_name);
	if (!o.is_open())
	{
		throw std::exception("Nu s-a putut deschide fisierul");
	}

	for (auto& i : tasks)
	{
		o << i.get_id() << '\n';
		o << i.get_descriere() << '\n';
		o << i.get_programatori().size() << '\n';
		for (auto& j : i.get_programatori())
			o << j << '\n';
		o << i.get_stare() << '\n';
	}
	o.close();
}

void Repo::add(const Task & task)
{
	std::vector<Task>::iterator it = find(tasks.begin(), tasks.end(), task);

	if (it != tasks.end())
		throw std::exception("Task-ul exista deja in repo");

	tasks.push_back(task);
	save_file();
}

void Repo::update(const int & id, const std::string stare)
{
	std::vector<Task>::iterator it = find(tasks.begin(), tasks.end(), id);

	it->set_stare(stare);
	save_file();
}

std::vector<Task>& Repo::get_all()
{
	return tasks;
}

Repo::~Repo()
{
}
