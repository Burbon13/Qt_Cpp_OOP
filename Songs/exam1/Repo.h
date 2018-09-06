#pragma once

#include <string>
#include <vector>
#include <exception>
#include "song.h"
#include <map>

class Repo
{
private:
	std::string file_name;
	std::vector<song> songs;
	void load_file();
	void save_file();
	std::map<std::string, int> map_genre;
	std::map<std::string, int> map_artist;
public:
	Repo(std::string file_name) : file_name{ file_name } {
		load_file();
	};

	void add(song s);
	void del(int id);
	std::vector<song>& get_all();
	int get_nr_artist(std::string artist);
	int get_nr_genre(std::string genre);


	~Repo();
};

