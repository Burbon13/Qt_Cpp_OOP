#pragma once

#include <assert.h>
#include "Task.h"
#include "Repo.h"
#include "Service.h"

void test_task()
{
	std::vector<std::string> v;
	v.push_back(std::string("Razvan Roatis"));
	v.push_back(std::string("Mihai Sus"));
	v.push_back(std::string("Daniel Bota"));

	Task t{ 1,"Notepad bun!", v, "open" };

	assert(t.get_descriere() == std::string("Notepad bun!"));
	assert(t.get_id() == 1);
	assert(t.get_programatori() == v);
	assert(t.get_stare() == std::string("open"));
	t.set_stare("closed");
	assert(t.get_stare() == std::string("closed"));
	assert(t == 1);
	assert(t == Task( 1,"Notepad bun!", v, "open" ));
}

void test_repo()
{
	Repo repo{ "test.txt" };

	assert(repo.get_all().size() == 2);
	repo.update(1, "closed");
	repo.update(1, "open");

	std::vector<std::string> v;
	v.push_back(std::string("Razvan Roatis"));
	v.push_back(std::string("Mihai Sus"));
	v.push_back(std::string("Daniel Bota"));

	try
	{
		repo.add(Task(1, "Notepad bun!", v, "open"));
	}
	catch (std::exception &e)
	{
		assert(e.what() == std::string("Task-ul exista deja in repo"));
	}

	Task t{ 3,"Notepad bun!", v, "open" };

	repo.add(t);
	assert(repo.get_all().size() == 3);
	repo.pop_back();
}

void test_service()
{
	Repo repo{ "test2.txt" };
	Service serv{ repo };

	assert(serv.get_sorted().size() == 4);

	assert(serv.get_by_stare("open").size() == 2);
	assert(serv.get_by_stare("closed").size() == 1);
	assert(serv.get_by_stare("inprogress").size() == 1);

	assert(serv.get_by_name("Razvan Roatis").size() == 2);
	assert(serv.get_by_name("gaga").size() == 0);
	assert(serv.get_by_name("Paul Ciobanu").size() == 3);

	std::vector<std::string> v;
	v.push_back(std::string("Razvan Roatis"));
	v.push_back(std::string("Mihai Sus"));
	v.push_back(std::string("Daniel Bota"));

	try
	{
		serv.add(0, "O scurta descirere", v, "inprogress");
	}
	catch (std::exception& e)
	{
		assert(e.what() == std::string("Id-ul trebuie sa fie intreg pozitiv"));
	}

	try
	{
		serv.add(1, "", v, "inprogress");
	}
	catch (std::exception& e)
	{
		assert(e.what() == std::string("Descrierea trebuie sa nu fie vida"));
	}

	try
	{
		std::vector<std::string> aux;
		serv.add(1, "O scurta descirere", aux, "inprogress");
	}
	catch (std::exception& e)
	{
		assert(e.what() == std::string("Trebuie sa avem programatori"));
	}

	try
	{
		serv.add(1, "dada", v, "gaga");
	}
	catch (std::exception& e)
	{
		assert(e.what() == std::string("Stare invalida"));
	}
	serv.add(7, "O scurta descriere", v, "open");
	assert(serv.get_sorted().size() == 5);
	serv.pop_id(7);
	assert(serv.get_sorted().size() == 4);
}

void test_all()
{
	test_task();
	test_repo();
	test_service();
}