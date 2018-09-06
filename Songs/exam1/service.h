#pragma once

#include "Repo.h"

class service
{
private:
	Repo & repo;
public:
	service(Repo &repo) : repo{ repo } {};

	std::vector<song>& get_all();

	void add(const int& id, const std::string& title, const std::string& artist, const std::string& genre);

	void del(const int&id);

	int how_many_genre(const std::string& genre);

	int get_nr_artist(std::string artist);
	int get_nr_genre(std::string genre);

	~service();
};

