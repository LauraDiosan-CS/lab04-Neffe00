#include"Service.h"

Service::Service()
{
}

Service::Service(Repo& repo)
{
	this->repo = repo;
}

Service::~Service()
{
}

int Service::noExpenses()
{
	return this->repo.noExpenses();
}


void Service::addExpense(int id, int day, int sum, const char* type)
{
	this->repo.addExpense(Expense(id, day, sum, type));
}

Expense Service::getExpense(int id)
{
	return this->repo.getExpense(id);
}

vector<Expense> Service::getExpenses()
{
	return this->repo.getExpenses();
}

void Service::updateExpense(int id, int newDay, int newSum, const char* newType)
{
	this->repo.updateExpense(id, Expense(id, newDay, newSum, newType));
}

void Service::deleteExpense(int id)
{
	this->repo.deleteExpense(id);
}

Service& Service::operator =(const Service& e)
{
	this->repo = e.repo;
	return*this;
}