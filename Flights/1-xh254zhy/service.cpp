#include "service.h"
#include <fstream>

void service::add(const int & id_flight, const int & time_travel, const int & nr_places, const std::string & start_city, const std::string & end_city)
{
	{
		if (start_city == end_city)
		{
			throw service_exception{ "orasPornire == orasSosire" };
		}
		if (nr_places < 1)
		{
			throw service_exception{ "nrLocuriLibere < 1" };
		}

		rep.add(flight{ id_flight,time_travel,nr_places,start_city,end_city });
	}
}

void service::del(const std::string & starting_city)
{
	std::vector<flight> aux = rep.get_all();

	for (auto& i : aux)
		if (i.get_start_city() == starting_city)
			rep.del(i.get_id_flight());
}

void service::exports(const int & time_limit, const std::string & file_name)
{
	std::ofstream o;
	o.open(file_name);
	if (!o.is_open())
	{
		throw(service_exception("Unable to open file\n"));
	}

	std::vector<flight> aux = rep.get_all();

	for(auto& i: aux)
		if (i.get_time_travel() < time_limit)
		{
			o << i.get_id_flight() << '\n';
			o << i.get_time_travel() << '\n';
			o << i.get_nr_places() << '\n';
			o << i.get_start_city() << '\n';
			o << i.get_end_city() << '\n';
		}

	o.close();
}
