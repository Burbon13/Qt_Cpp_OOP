#pragma once

#include <assert.h>
#include "flight.h"
#include "repo.h"
#include "service.h"

void test_flight()
{
	flight f{ 3,1000,144,"Brasov","Bucuresti" };

	assert(f.get_end_city() == std::string{ "Bucuresti" });
	assert(f.get_start_city() == std::string{"Brasov"});
	assert(f.get_id_flight() == 3);
	assert(f.get_nr_places() == 144);
	assert(f.get_time_travel() == 1000);

	assert(f == flight(3, 3, 3, "", ""));
}

void test_repo()
{
	repo r{ "test.txt" };

	std::vector<flight> ha = r.get_all();

	assert(ha.size() == 10);

	r.add(flight{ 11, 1000, 300, "Ungaria", "Romania" });

	assert(r.get_all().size() == 11);

	r.del(11);
}

void test_service()
{
	repo r{"test.txt"};
	service s{ r };

	s.add(11, 1000, 100, "MONGOLIA", "STUDAL");
	s.add(12, 1000, 100, "MONGOLIA", "bucale");

	assert(r.get_all().size() == 12);

	s.del("MONGOLIA");

	assert(r.get_all().size() == 10);

	s.exports(501, "exporturi.txt");
}

void test_all()
{
	test_flight();
	test_repo();
	test_service();
}