#pragma once

#include <string>
#include "repo.h"

class service_exception
{
	std::string error;
public:
	/*
	Constructor
	in:
	error - std::string - the error message to be sent
	*/
	service_exception(const std::string &error) : error{ error } {};

	/*
	Returns the error code
	out: std::string - the error message
	*/
	std::string get_error()
	{
		return error;
	}
};

class service
{
private:
	repo & rep;
public:
	service(repo &rep): rep { rep } {};
	~service() = default;

	/*
	Adds a car to the repo
	In:
	id_flight - int - identification number
	time_travel - int - how much time the flight takes
	nr_places - int - nr of free placers left
	start_city - std::string - starting city of flight
	end_city - std::string - ending city of flight
	*/
	void add(const int& id_flight, const int& time_travel, const int& nr_places,
		const std::string& start_city, const std::string& end_city);

	/*
	Deletes all flights from repo starting from starting_city
	in:
	starting_city - std::string
	*/
	void del(const std::string& starting_city);

	/*
	Exports all flights shorten than given time to a file
	in:
	time_limit - int - the superior time limit for exporting flights
	file_name - std::string - the file in which the flights will be exported
	*/
	void exports(const int& time_limit, const std::string& file_name);

	std::vector<flight>& get_ref()
	{
		return rep.get_all();
	}

	flight get_f(const int&id)
	{
		return rep.get_id(id);
	}
};

