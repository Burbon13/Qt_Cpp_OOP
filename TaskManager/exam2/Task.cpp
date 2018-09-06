#include "Task.h"


int Task::get_id()
{
	return id;
}

std::string Task::get_descriere()
{
	return descriere;
}

std::vector<std::string> Task::get_programatori()
{
	return programatori;
}

std::string Task::get_stare()
{
	return stare;
}

void Task::set_stare(const std::string & stare)
{
	this->stare = stare;
}

Task::~Task()
{
}

bool Task::operator==(const int & nr)
{
	return nr == this->id;
}

bool Task::operator==(const Task & task)
{
	return task.id == this->id;
}
