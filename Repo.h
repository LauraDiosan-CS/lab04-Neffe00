#pragma once

#include<vector>
#include"Expense.h"

class Repo
{
private:
	vector<Expense> expenses;
public:
	Repo();
	~Repo();

	int noExpenses();

	void addExpense( Expense e );
	Expense getExpense( int id );
	vector<Expense> getExpenses();
	void updateExpense(int id, const Expense& newExpense);
	void deleteExpense(int id);
};
