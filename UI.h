#pragma once

#include"Service.h"

class UI
{
private:
	Service service;
	void displayMenu();

	void UIaddExpense(string  cmd);
	void UIinsertExpense(string  cmd);

	void UIdeleteExpense(string  cmd);

	void UIgetExpenses(string  cmd);

	void UIsumExpense(string cmd);
	void UImaxExpense(string cmd);
	void UIsortExpense(string cmd);

	void UIfilterExpense(string cmd);

public:
	UI();
	UI(Service& service);
	~UI();
	void runUI();
};