#include "teste.h"
#include "costuri.h"
#include "repo.h"
#include <string.h>
#include <cassert>
#include <iostream>
#define strcpy_s

void test_costs()
{
	char* type_1 = new char[20];
	char* type_2 = new char[20];
	strcpy_s(type_1, strlen("Internet") + 1, "Internet");
	strcpy_s(type_2, strlen("Mancare") + 1, "Mancare");
	Costs c1(10, 12, type_1);
	Costs c2(2, 32, type_2);
	
	assert(c1.get_day() == 10);
	assert(c2.get_sum() == 32);
	
	
	c1.set_day(5);
	c2.set_type(type_1);	
	c2.set_sum(21);
	
	assert(c1.get_day() == 5);
	assert(c2.get_sum() == 21);
	cout << "OK\n";
}

void test_repo_costs()
{
	char* type_1 = new char[10];
	char* type_2 = new char[10];
	
	strcpy_s(type_1, strlen("Apa") + 1, "Apa");
	strcpy_s(type_2, strlen("Gaz") + 1, "Gaz");
	
	Costs c1(5, 65, type_1);
	Costs c2(12, 13, type_2);
	
	Repo repo_costs;
	repo_costs.add(c1);
	repo_costs.add(c2);
	
	assert(repo_costs.get_size() == 2);
	assert(repo_costs.show()[0] == c1);
	assert(repo_costs.show()[1] == c2);
	cout << "OK\n";
}
