#include "repo.h"

#include <fstream>
#include <algorithm>

void repo::add(const flight & f)
{
	flights.push_back(f);
	save_file();
}

void repo::load_file()
{
	std::ifstream f;
	f.open(file_name);

	if (!f.is_open())
	{
		throw repo_exception("Unable to open file!");
	}

	int id_flight;
	int time_travel;
	int nr_places;
	std::string start_city;
	std::string end_city;
	while (f >> id_flight)
	{
		f >> time_travel >> nr_places >> start_city >> end_city;
		flights.push_back(flight{ id_flight,time_travel,nr_places,start_city,end_city });
	}

	f.close();
}

void repo::save_file()
{
	std::ofstream o(file_name);

	if (!o.is_open())
	{
		throw repo_exception("Unable to open file!");
	}

	for (auto i : flights)
	{
		o << i.get_id_flight() << '\n';
		o << i.get_time_travel() << '\n';
		o << i.get_nr_places() << '\n';
		o << i.get_start_city() << '\n';
		o << i.get_end_city() << '\n';
	}
	o.close();
}


std::vector<flight>& repo::get_all()
{
	return flights;
}

void repo::del(const int &id)
{
	flights.erase(find(flights.begin(), flights.end(), id));
	save_file();
}

flight repo::get_id(const int&id)
{
	std::vector<flight>::iterator it = find(flights.begin(), flights.end(), id);
	if (it == flights.end())
		throw repo_exception("Nu exista!");
	return *it;
}