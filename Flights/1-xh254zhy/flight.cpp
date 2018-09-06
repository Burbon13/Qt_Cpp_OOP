#include "flight.h"

int flight::get_id_flight()
{
	return id_flight;
}

int flight::get_time_travel()
{
	return time_travel;
}

int flight::get_nr_places()
{
	return nr_places;
}

std::string flight::get_start_city()
{
	return start_city;
}

std::string flight::get_end_city()
{
	return end_city;
}

bool flight::operator==(const flight &f)
{
	return id_flight == f.id_flight;
}

bool flight::operator==(const int &id)
{
	return id_flight == id;
}
