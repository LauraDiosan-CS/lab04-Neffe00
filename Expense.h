#pragma once

#include<ostream>
using namespace std;

class Expense
{
private:
	int id;
	int day;
	int sum;
	char* type;

public:
	Expense();
	Expense(int id, int d, int s, const char* t);
	Expense(const Expense& e);
	~Expense();

	int getId();
	int getDay();
	int getSum();
	char* getType();

	void setId(int newId);
	void setDay(int newDay);
	void setSum(int newSum);
	void setType(const char* newType);

	Expense& operator =(const Expense& e);
	bool operator ==(const Expense& e);
	bool operator <(const Expense& e);
	friend ostream& operator<<(ostream& os, const Expense& e);
};