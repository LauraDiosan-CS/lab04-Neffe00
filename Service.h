#pragma once

#include"Repo.h"

class Service
{
private:
	Repo repo;
public:
	Service();
	Service(Repo& repo);
	~Service();

	int noExpenses();

	void addExpense(int id, int day, int sum, const char* type);
	Expense getExpense(int id);
	vector<Expense> getExpenses();
	void updateExpense(int id, int newDay, int newSum, const char* newType);
	void deleteExpense(int id);
	Service& operator =(const Service& e);

};