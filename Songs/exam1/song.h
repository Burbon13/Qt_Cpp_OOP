#pragma once

#include <string>

class song
{
private:
	int id;
	std::string title, artist, genre;
public:
	song(const int& id, const std::string& title, const std::string& artist, const std::string& genre) :
		id{ id }, title{ title }, artist{ artist }, genre{ genre } {};

	int get_id();
	std::string get_title();
	std::string get_artist();
	std::string get_genre();

	bool operator==(const int&);
	bool operator==(const song&);

	~song();
};

