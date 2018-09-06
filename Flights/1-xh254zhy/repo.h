#pragma once

#include <vector>
#include "flight.h"

class repo_exception
{
private:
	std::string error;
public:
	repo_exception(const std::string &error) : error{ error } {};

	std::string get_error()
	{
		return error;
	}
};

class repo
{
private:
	std::vector<flight> flights;
	std::string file_name;
public:
	repo() = default;
	repo(const std::string file_name) : file_name{ file_name } { 
		load_file();
	};
	~repo() = default;

	/*
	Adds a flight to repo
	in: f - flight refference
	*/
	void add(const flight& f);

	/*
	Loads the repo from file
	*/
	void load_file();

	/*
	Saves the repo to file
	*/
	void save_file();

	/*	
	Returns refference to repo vector
	out: std::Vector<flight>&
	*/
	std::vector<flight>& get_all();

	/*
	Deletes a flight
	In: const int - flight's id
	*/
	void del(const int&);

	flight get_id(const int&);
};

