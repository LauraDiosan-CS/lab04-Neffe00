#include"Tests.h"

#include"Service.h"
#include"Expense.h"
#include"Repo.h"

#include<assert.h>

#include<iostream>
using namespace std;

void test_expense()
{
	Expense e1(1, 1, 50, "internet");
	assert(e1.getId() == 1);
	assert(e1.getDay() == 1);
	assert(e1.getSum() == 50);
	assert(strcmp(e1.getType(), "internet") == 0);


	Expense e2;
	e2.setId(2);
	e2.setDay(2);
	e2.setSum(100);
	e2.setType("mancare");
	assert(e2.getId() == 2);
	assert(e2.getDay() == 2);
	assert(e2.getSum() == 100);
	assert(strcmp(e2.getType(), "mancare") == 0);

	//cout << e1 << e2;

	assert(!(e1 == e2));
	e1 = e2;
	assert(e1 == e2);

	cout << "Expense tests are good" << endl;
}

void test_repo()
{
	Repo repo;

	Expense e1(1, 1, 50, "internet");
	Expense e2(2, 2, 100, "mancare");

	repo.addExpense(e1);
	repo.addExpense(e2);

	/*vector<Expense> expenses = repo.getExpenses();
	vector<Expense>::iterator it;
	for (it = expenses.begin(); it != expenses.end(); it++)
		cout << *it;*/

	assert(repo.getExpense(1)==e1);
	assert(repo.getExpense(2)==e2);
	assert(repo.noExpenses() == 2);
	
	Expense e3(1, 3, 200, "haine");
	repo.updateExpense(1, e3);
	
	assert(repo.getExpense(1) == e3);
	
	repo.deleteExpense(1);
	repo.deleteExpense(2);
	assert(repo.noExpenses() == 0);

	
	cout << "Repo tests are good" << endl;
}

void test_service()
{
	Repo repo;
	Service service(repo);

	service.addExpense(1, 1, 50, "internet");
	service.addExpense(2, 2, 100, "mancare");
	assert(service.noExpenses() == 2);

	/*vector<Expense> expenses = service.getExpenses();
	vector<Expense>::iterator it;
	for (it = expenses.begin(); it != expenses.end(); it++)
		cout << *it;*/


	Expense e1(1, 1, 50, "internet");
	Expense e2(2, 2, 100, "mancare");
	assert(service.getExpense(1) == e1);
	assert(service.getExpense(2) == e2);

	Expense e3(1, 3, 200, "haine");
	service.updateExpense(1, 3, 200, "haine");
	assert(service.getExpense(1) == e3);

	service.deleteExpense(1);
	service.deleteExpense(2);
	assert(service.noExpenses() == 0);


	cout << "Repo tests are good" << endl;


}