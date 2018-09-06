#pragma once

#include "Repo.h"
#include "obs_ervable.h"
#include "observer.h"

class Service : public Observable
{
private:
	Repo & repo;
public:
	Service(Repo &repo) : repo{ repo } {};

	/*
	Return a refference to the sorted vector from repo
	return: std::vector<Task> &;
	*/
	std::vector<Task>& get_sorted();

	/*
	Adds a task to repo
	in:
	id - int
	descriere - std:::string
	programatori - std::Vector<std::string>
	stare - std::string
	*/
	void add(const int& id, const  std::string& descriere, const  std::vector<std::string>& programatori, const  std::string& stare);
	
	/*
	Return all the tasks which have a programer name
	in: name = std::string
	out- std::Vector<Task>
	*/
	std::vector<Task> get_by_name(const std::string& name);

	/*
	Returns all task with a given state
	in: stare - std::string
	return: std::vector<Task>
	*/
	std::vector<Task> get_by_stare(const std::string& stare);

	/*

	*/
	void set_stare(const int& id, const std::string &stare);

	/*
	Pops last element from repo
	*/
	void pop_back()
	{
		repo.pop_back();
	}

	void pop_id(int id)
	{
		repo.pop_id(id);
	}

	~Service();
};

