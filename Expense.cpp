#include "Expense.h"

#include<string.h>

Expense::Expense()
{
	this->id = 0;
	this->day = 0;
	this->sum = 0;
	this->type = NULL;
}
Expense::Expense(int id, int d, int s, const char* t)
{
	this->id = id;
	this->day = d;
	this->sum = s;

	this->type = new char[strlen(t) + 1];
	strcpy_s(this->type, strlen(t) + 1, t);
}
Expense::Expense(const Expense& e)
{
	this->id = e.id;
	this->day = e.day;
	this->sum = e.sum;

	this->type = new char[strlen(e.type) + 1];
	strcpy_s(this->type, strlen(e.type) + 1, e.type);
}
Expense::~Expense()
{
	this->id = 0;
	this->day = 0;
	this->sum = 0;
	if (this->type)
	{
		delete[] this->type;
		this->type = NULL;
	}
}

int Expense::getId()
{
	return this->id;
}

int Expense::getDay()
{
	return this->day;
}

int Expense::getSum()
{
	return this->sum;
}
char* Expense::getType()
{
	return this->type;
}

void Expense::setId(int newId)
{
	this->id = newId;
}

void Expense::setDay(int newDay)
{
	this->day = newDay;
}
void Expense::setSum(int newSum)
{
	this->sum = newSum;
}

void Expense::setType(const char* newType)
{
	if (this->type != NULL)
	{
		delete[] this->type;
		this->type = NULL;
	}

	this->type = new char[strlen(newType) + 1];
	strcpy_s(this->type, strlen(newType) + 1, newType);
}

Expense& Expense::operator =(const Expense& e)
{
	this->setId(e.id);
	this->setDay(e.day);
	this->setSum(e.sum);
	this->setType(e.type);
	return*this;
}
bool Expense::operator ==(const Expense& e)
{
	return this->id == e.id;
}

bool Expense::operator <(const Expense& e)
{
	if (this->sum < e.sum)
		return true;
	return false;
}

ostream& operator<<(ostream& os, const Expense& e)
{
	os << e.id << " day: " << e.day << "  sum: " << e.sum << "  type: " << e.type << endl;
	return os;
}