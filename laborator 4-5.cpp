#include"Tests.h"
#include"UI.h"

#include <iostream>
using namespace std;

int main()
{
	/*test_expense();
	test_repo();
	test_service();
	cout << endl << endl;*/

	Repo repo;
	Service service(repo);

	service.addExpense(1, 1, 20, "mancare");
	service.addExpense(2, 1, 50, "internet");
	service.addExpense(3, 2, 5, "transport");
	service.addExpense(4, 3, 25, "menaj");
	service.addExpense(5, 4, 50, "internet");
	service.addExpense(6, 5, 100, "haine");
	service.addExpense(7, 6, 40, "mancare");
	service.addExpense(8, 7, 10, "transport");
	service.addExpense(9, 8, 20, "haine");
	service.addExpense(10, 9, 15, "menaj");
	service.addExpense(11, 10, 50, "internet");
	service.addExpense(12, 11, 20, "mancare");
	service.addExpense(13, 12, 15, "mancare");
	service.addExpense(14, 13, 20, "transport");
	service.addExpense(15, 14, 100, "haine");
	service.addExpense(16, 15, 70, "internet");

	UI ui(service);
	ui.runUI();

	return 0;
}
