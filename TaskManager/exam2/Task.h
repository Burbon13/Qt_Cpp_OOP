#pragma once

#include <string>
#include <vector>

class Task
{
private:
	int id;
	std::string descriere;
	std::vector<std::string> programatori;
	std::string stare;
public:
	Task(const int&id, const std::string& descriere, const std::vector<std::string>& programatori, const std::string &stare) :
		id{ id }, descriere{ descriere }, programatori{ programatori }, stare{ stare } {};

	/*
	Getter for id
	Returns int
	*/
	int get_id();

	/*
	Getter for descreire
	return std::string
	*/
	std::string get_descriere();

	/*
	getter for programatori
	return std::vector<std::string> containing the programmers
	*/
	std::vector<std::string> get_programatori();

	/*
	Getter for stare
	Return std::string
	*/
	std::string get_stare();

	/*
	Setter for stare
	In: stare - std::string
	*/
	void set_stare(const std::string& stare);
	~Task();

	bool operator==(const int& nr);

	bool operator==(const Task& task);
};

