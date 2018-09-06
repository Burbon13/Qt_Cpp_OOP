#pragma once

#include <string>

class flight
{
private:
	int id_flight;
	int time_travel;
	int nr_places;
	std::string start_city;
	std::string end_city;
public:
	flight() = default;
	flight(int id_flight, int time_travel, int nr_places, std::string start_city, std::string end_city) :
		id_flight{ id_flight }, time_travel{ time_travel }, nr_places{ nr_places }, start_city{ start_city }, end_city{ end_city } {};

	//getters for all variables
	int get_id_flight();
	int get_time_travel();
	int get_nr_places();
	std::string get_start_city();
	std::string get_end_city();

	bool operator==(const flight&);
	bool operator==(const int&);

	~flight() = default;
};

