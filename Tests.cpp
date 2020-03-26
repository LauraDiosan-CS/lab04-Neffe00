#include "Tests.h"
#include "Costs.h"
#include "Repo.h"
#include "Service.h"

#include <string.h>
#include <cassert>
#include <iostream>
#include <assert.h>

void test_costs()
{
	char* type_1 = new char[10];
	strcpy_s(type_1, strlen("internet") + 1, "internet");
	Costs c(1, 5, 50, type_1);
	//getteri
	assert(c.get_id == 1);
	assert(c.get_day() == 5);
	assert(c.get_sum() == 50);
	assert(strcmp(c.get_type(), "internet") == 0);
	
	//setteri
	c.set_id(2);
	c.set_day(6);
	c.set_sum(100);
	char* type_2 = new char[10];
	strcpy_s(type_2, strlen("haine") + 1, "haine");
	c.set_type(type_2);
	assert(c.get_id == 2);
	assert(c.get_day() == 6);
	assert(c.get_sum() == 100);
	assert(strcmp(c.get_type(), "haine") == 0);

	// =
	Costs c2 = c;
	assert(c2.get_day() == 6);
	assert(c2.get_sum() == 100);
	assert(strcmp(c2.get_type(), "haine") == 0);
	assert(c == c2);

	cout << "Testele pentru Costs sunt ok!\n";
}

void test_repo_costs()
{
	char* type_1 = new char[10];
	strcpy_s(type_1, strlen("Internet") + 1, "Internet");
	Costs c1(1, 5, 50, type_1);

	char* type_2 = new char[10];
	strcpy_s(type_2, strlen("Haine") + 1, "Haine");
	Costs c2(2, 6, 75, type_2);


	Repo repo_costs;
	repo_costs.create(c1);
	repo_costs.create(c2);

	assert(repo_costs.get_size() == 2);
	assert(repo_costs.read()[0] == c1);
	assert(repo_costs.read()[1] == c2);
	cout << "Testele pentru Repo Costs sunt OK!\n";
}


void test_service_costs()
{
	char* type_1 = new char[10];
	strcpy_s(type_1, strlen("Internet") + 1, "Internet");
	Costs c1(1, 5, 50, type_1);

	char* type_2 = new char[10];
	strcpy_s(type_2, strlen("Haine") + 1, "Haine");
	Costs c2(2, 6, 75, type_2);

	Service service;

	char* type_1 = new char[10];
	strcpy_s(type_1, strlen("Internet") + 1, "Internet");
	
	service.create_cost(1, 5, 10, type_1);
	
	char* type_2 = new char[10];
	strcpy_s(type_2, strlen("haine") + 1, "haine");

	service.update_cost(1, 5, 10, type_1,1, 6, 20, type_2);
	service.delete_cost(1);

	assert(service.read_cost()[0] == c1);
	assert(service.read_cost()[1] == c2);

	cout << "Testele pentru Service Costs sunt OK!\n";

}