#include "song.h"

int song::get_id()
{
	return id;
}

std::string song::get_title()
{
	return title;
}

std::string song::get_artist()
{
	return artist;
}

std::string song::get_genre()
{
	return genre;
}

bool song::operator==(const int &id)
{
	return this->id == id;
}

bool song::operator==(const song &s)
{
	return this->id == s.id;
}

song::~song()
{
}
