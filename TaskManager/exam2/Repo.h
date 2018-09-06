#pragma once

#include "Task.h"
#include <string>

class Repo
{
private:
	std::vector<Task> tasks;
	std::string file_name;
	void load_file();
	void save_file();
public:
	Repo(const std::string& file_name) : file_name{ file_name } {
		load_file();
	};

	/*
	Adds a task to the repo
	In: task - Task instance
	@if task already exists, exception is thrown
	*/
	void add(const Task& task);

	/*
	Updates a task in the repo
	In: id - int id for the taskj to pe udpated
	stare - std::string - new state
	*/
	void update(const int& id, const std::string stare);
	
	/*
	Return refference to vector repo
	out: std::Vector<Task> &;
	*/
	std::vector<Task>& get_all();

	/*
	Pops the last element out of the repo
	*/
	void pop_back()
	{
		tasks.pop_back();
		save_file();
	}

	void pop_id(int id)
	{
		tasks.erase(find(tasks.begin(), tasks.end(), id));
		save_file();
	}

	~Repo();
};

