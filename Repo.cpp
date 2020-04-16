#include"Repo.h"

Repo::Repo()
{}

Repo::~Repo()
{}

int Repo::noExpenses()
{
	return this->expenses.size();
}

void Repo::addExpense(Expense e)
{
	this->expenses.push_back(e);
}

Expense Repo::getExpense(int id)
{
	vector<Expense> ::iterator it;
	for (it = this->expenses.begin(); !(it == this->expenses.end()); it++)
		if ((*it).getId() == id)
			return *it;
}

vector<Expense> Repo::getExpenses()
{
	return this->expenses;
}

void Repo::updateExpense(int id, const Expense& newExpense)
{
	vector<Expense> ::iterator it;
	for (it = this->expenses.begin(); !(it == this->expenses.end()); it++)
		if ((*it).getId() == id)
			*it = newExpense;
}

void Repo::deleteExpense(int id)
{
	vector<Expense> ::iterator it;
	for (it = this->expenses.begin(); !(it == this->expenses.end()); it++)
		if ( (*it).getId() == id )
		{
			this->expenses.erase(it);
			break;
		}
}
