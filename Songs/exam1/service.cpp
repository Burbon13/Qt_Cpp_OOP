#include "service.h"


std::vector<song>& service::get_all()
{
	return repo.get_all();
}

void service::add(const int & id, const std::string & title, const std::string & artist, const std::string & genre)
{
	if (id < 1)
		throw std::exception("Id invalid");
	if(title.size() == 0)
		throw std::exception("Titlu vid");
	if (artist.size() == 0)
		throw std::exception("Artist vid");
	if (genre != std::string("pop") && genre != std::string("rock") && genre != std::string("folk") && genre != std::string("disco"))
		throw std::exception("Gen invalid!");

	repo.add(song(id, title, artist, genre));
}

void service::del(const int & id)
{
	repo.del(id);
}

int service::how_many_genre(const std::string & genre)
{
	int total = 0;
	for (auto& i : repo.get_all())
		if (i.get_genre() == genre)
			total++;
	return total;
}

int service::get_nr_artist(std::string artist)
{
	return repo.get_nr_artist(artist);
}

int service::get_nr_genre(std::string genre)
{
	return repo.get_nr_genre(genre);
}

service::~service()
{
}
