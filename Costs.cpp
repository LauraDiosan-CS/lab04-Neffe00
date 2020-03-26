#include "Costs.h"

#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>

using namespace std;

Costs::Costs()
{
	this->id = 0;
	this->day = 0;
	this->sum = 0;
	this->type = NULL;
}

Costs::Costs(int id, int day, int sum, char* type)
{
	this->id = id;
	this->day = day;
	this->sum = sum;
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

Costs::Costs(const Costs& c)
{
	this->id = c.id;
	this->day = c.day;
	this->sum = c.sum;
	this->type = new char[strlen(c.type) + 1];
	strcpy_s(this->type, strlen(c.type) + 1, c.type);
}

Costs::~Costs()
{
	this->id = 0;
	this->day = 0;
	this->sum = 0;
	if (this->type != NULL)
	{
		delete[] this->type;
		this->type = NULL;
	}
}

int Costs::get_id()
{
	return this->id;
}

int Costs::get_day()
{
	return this->day;
}

int Costs::get_sum()
{
	return this->sum;
}

char* Costs::get_type()
{
	return this->type;
}

void Costs::set_id(int id)
{
	this->id = id;
}

void Costs::set_day(int day)
{
	this->day = day;
}

void Costs::set_sum(int sum)
{
	this->sum = sum;
}

void Costs::set_type(char* type)
{
	if (this->type != NULL)
	{
		delete[] this->type;
		this->type = NULL;
	}
	this->type = new char[strlen(type) + 1];
	strcpy_s(this->type, strlen(type) + 1, type);
}

Costs& Costs::operator=(const Costs& c)
{
	this->set_id(c.id);
	this->set_day(c.day);
	this->set_sum(c.sum);
	this->set_type(c.type);
	return *this;
}

bool Costs::operator==(const Costs& c)
{
	return  (this->id == c.id) && (this->day == c.day) && (this->sum == c.sum) && (strcmp(this->type, c.type) == 0);
}

ostream& operator<<(ostream& os, const Costs& c)
{
	os << "Day: " << c.day << "\nSum: " << c.sum << "\nType: " << c.type;
	return os;
}
