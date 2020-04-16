#include"UI.h"

#include<iostream>
using namespace std;

#include<string>
#include <algorithm>  

#include<ctime>
int getCurrentDay()
{
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int day = newtime.tm_mday;
	return day;
}

UI::UI()
{
}

UI::UI(Service& service)
{
	this->service = service;
}

UI::~UI()
{
}


void UI::displayMenu()
{
	cout << "ADD expense to current day: 'add' +  id +  sum +   type" << endl;
	cout << "INSERT expense: 'insert' + id +  day +  sum +   type" << endl << endl;

	cout << "DELETE expense from a day: 'delete' + day" << endl;
	cout << "DELETE expenses from a period: 'delete' + startDay + 'to' + endDay" << endl;
	cout << "DELETE a type of expenses: 'delete' + type" << endl << endl;;

	cout << "SHOW all expenses: 'show'" << endl;
	cout << "SHOW all expenses for a type: 'show' + type" << endl;
	cout << "SHOW all expenses for a type greater than a value: 'show' + type + '>' + value" << endl;
	cout << "SHOW all expenses for a type equal to a value: 'show' + type + '=' + value" << endl<<endl;

	cout << "SUM all expenses for a type: 'sum' + type" << endl;
	cout << "MAX of all expenses of a day: 'max' + day" << endl;
	cout << "SORT all expenses for a type: 'sort' + type" << endl << endl;

	cout << "FILTER all expenses by a type: 'filter' + type" << endl;
	cout << "FILTER all expenses by a type smaller than a value: 'filter' + type + '<' + value" << endl;
	cout << "FILTER all expenses by a type smaller equal to value: 'filter' + type + '' + value" << endl << endl;

	cout << "EXIT program: 'exit'" << endl;
	cout << endl << endl << endl;
}

void UI::UIaddExpense(string  cmd)//adda marafet 50
{
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + 1);

	pos = cmd.find(sep);
	string token = cmd.substr(0, pos);
	int id = stoi(token);
	cmd.erase(0, pos + 1);

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int sum = stoi(token);
	cmd.erase(0, pos + 1);

	token = cmd;
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.addExpense(id, getCurrentDay(), sum, type);
}

void UI::UIinsertExpense(string  cmd)
{
	//stergem insert
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + 1);

	pos = cmd.find(sep);
	string token = cmd.substr(0, pos);
	int id = stoi(token);
	cmd.erase(0, pos + 1);

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int day = stoi(token);
	cmd.erase(0, pos + 1);

	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int sum = stoi(token);
	cmd.erase(0, pos + 1);

	token = cmd;
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	this->service.addExpense(id, day, sum, type);
}

void UI::UIdeleteExpense(string  cmd)
{
	//numaram cuvintele
	int wordCount = 1;
	string sep = " ";
	string cmdCopy = cmd;

	while (cmdCopy.find(sep) != string::npos)
	{
		size_t pos = cmdCopy.find(sep);
		cmdCopy.erase(0, pos+1);
		wordCount++;
	}

	//eliminam cuvantul delete
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + 1);

	if (wordCount == 2)
	{
		//verificam daca cuvantul ramas este numar (daca este data, nu un tip)
		bool isNumber=true;
		for (int i = 0; i < cmd.length(); i++)
			if (isdigit(cmd[i]) == false)
				isNumber = false;
		
		if (isNumber == true)
		{
			//sterge cheltuielile dintr-o anumita zi
			string token = cmd;
			int day = stoi(token);

			vector<Expense> expenses = this->service.getExpenses();
			vector<Expense> ::iterator it;
			for (it = expenses.begin(); it != expenses.end(); it++)
				if ((*it).getDay() == day)
					this->service.deleteExpense( (*it).getId() );
		}
		else
		{
			//sterge cheltuielile de un anumit tip
			string token = cmd;
			char* type = new char[token.length()+1];
			strcpy_s(type, token.length() + 1, token.c_str());

			vector<Expense> expenses = this->service.getExpenses();
			vector<Expense> ::iterator it;
			for (it = expenses.begin(); it != expenses.end(); it++)
				if ( strcmp( (*it).getType(), type )==0 )
					this->service.deleteExpense((*it).getId());
		}
	}
	else if (wordCount == 4)
	{
		//sterge cheltuielile dintr-un interval

		string sep = " ";
		size_t pos = cmd.find(sep);
		string token = cmd.substr(0, pos);
		int startDay = stoi(token);
		cmd.erase(0, pos + 1);

		//eliminam " to "
		pos = cmd.find(sep);
		cmd.erase(0, pos + 1);

		token = cmd;
		int endDay = stoi(token);

		vector<Expense> expenses = this->service.getExpenses();
		vector<Expense> ::iterator it;

		for( int day = startDay ; day <= endDay ; day++ )
			for (it = expenses.begin(); it != expenses.end(); it++)
				if ((*it).getDay() == day)
					this->service.deleteExpense((*it).getId());
	}

}

void UI::UIgetExpenses(string cmd)
{
	//numaram cuvintele
	int wordCount = 1;
	string sep = " ";
	string cmdCopy = cmd;

	while (cmdCopy.find(sep) != string::npos)
	{
		size_t pos = cmdCopy.find(sep);
		cmdCopy.erase(0, pos + 1);
		wordCount++;
	}

	//eliminam cuvantul show
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + 1);

	if (wordCount == 1)
	{
		//afisam toate cheltuielile
		vector<Expense> expenses = this->service.getExpenses();
		vector<Expense> ::iterator it;
		for (it = expenses.begin(); it != expenses.end(); it++)
			cout << *it;
	}
	else if (wordCount == 2)
	{
		//aflam tipul
		string token = cmd;
		char* type = new char[token.length() + 1];
		strcpy_s(type, token.length() + 1, token.c_str());

		vector<Expense> expenses = this->service.getExpenses();
		vector<Expense> ::iterator it;
		for (it = expenses.begin(); it != expenses.end(); it++)
			if (strcmp((*it).getType(), type) == 0)
				cout << *it;
	}
	else if (wordCount == 4)
	{

		//gasim tipul
		string sep = " ";
		size_t pos = cmd.find(sep);
		string token = cmd.substr(0, pos);
		char* type = new char[token.length() + 1];
		strcpy_s(type, token.length() + 1, token.c_str());
		cmd.erase(0, pos + 1);

		//aflam daca operatorul ramas este > sau =
		token = cmd.substr(0, 1);
		char* op = new char[2];
		strcpy_s(op, 2, token.c_str());
		cmd.erase(0, 2);

		//gasim suma minima
		token = cmd;
		int sum = stoi(token);

		if (strcmp(op, ">") == 0)
		{
			vector<Expense> expenses = this->service.getExpenses();
			vector<Expense> ::iterator it;
			for (it = expenses.begin(); it != expenses.end(); it++)
				if (strcmp((*it).getType(), type) == 0 && (*it).getSum() >= sum)
					cout << *it;
		}
		else if (strcmp(op, "=") == 0)
		{
			vector<Expense> expenses = this->service.getExpenses();
			vector<Expense> ::iterator it;
			for (it = expenses.begin(); it != expenses.end(); it++)
				if (strcmp((*it).getType(), type) == 0 && (*it).getSum() == sum)
					cout << *it;
		}
	}
}

void UI::UIsumExpense(string cmd)
{
	//stergem sum
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + 1);

	//aflam tipul
	string token = cmd;
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());

	//calculam suma
	int sum = 0;
	vector<Expense> expenses = this->service.getExpenses();
	vector<Expense> ::iterator it;
	for (it = expenses.begin(); it != expenses.end(); it++)
		if (strcmp((*it).getType(), type) == 0)
			sum += (*it).getSum();

	cout << "sum " << type << ": " << sum << endl;;
}

void UI::UImaxExpense(string cmd)
{
	//stergem max
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + 1);

	//aflam ziua
	string token = cmd;
	int day = stoi(token);

	//calculam max
	int max = -1;
	int idMax = -1;
	vector<Expense> expenses = this->service.getExpenses();
	vector<Expense> ::iterator it;
	for (it = expenses.begin(); it != expenses.end(); it++)
		if ((*it).getDay() == day && max < (*it).getSum())
		{
			max = (*it).getSum();
			idMax = (*it).getId();
		}
			

	cout << "max " << day << ": " << max << "    id:" << idMax << endl;
}

void UI::UIsortExpense(string cmd)
{
	//stergem sort
	string sep = " ";
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + 1);


	//aflam tipul
	string token = cmd;
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());


	//memoram toate cheltuielile de acest tip
	vector<Expense> sortedExpenses;
	
	vector<Expense> expenses = this->service.getExpenses();
	vector<Expense> ::iterator it;
	for (it = expenses.begin(); it != expenses.end(); it++)
		if (strcmp((*it).getType(), type) == 0)
			sortedExpenses.push_back(*it);

	//afisam cheltuielile sortate
	sort(sortedExpenses.begin(), sortedExpenses.end());
	for (it = sortedExpenses.begin(); it != sortedExpenses.end(); it++)
		cout << *it;
}

void UI::UIfilterExpense(string  cmd)
{
	//numaram cuvintele
	int wordCount = 1;
	string sep = " ";
	string cmdCopy = cmd;

	while (cmdCopy.find(sep) != string::npos)
	{
		size_t pos = cmdCopy.find(sep);
		cmdCopy.erase(0, pos + 1);
		wordCount++;
	}

	//eliminam cuvantul filter
	size_t pos = cmd.find(sep);
	cmd.erase(0, pos + 1);

	//gasim tipul
	pos = cmd.find(sep);
	string token = cmd.substr(0, pos);
	char* type = new char[token.length() + 1];
	strcpy_s(type, token.length() + 1, token.c_str());
	cmd.erase(0, pos + 1);

	if (wordCount == 2)
	{
		//verificam daca cuvantul ramas este numar (daca este data, nu un tip)
		bool isNumber = true;
		for (int i = 0; i < cmd.length(); i++)
			if (isdigit(cmd[i]) == false)
				isNumber = false;

		//pastreaza cheltuielile de un anumit tip

		vector<Expense> expenses = this->service.getExpenses();
		vector<Expense> ::iterator it;
		for (it = expenses.begin(); it != expenses.end(); it++)
			if (strcmp((*it).getType(), type) != 0)
				this->service.deleteExpense((*it).getId());
	}
	else if (wordCount == 4)
	{
		//aflam daca operatorul ramas este > sau =
		string token = cmd.substr(0, 1);
		char* op = new char[2];
		strcpy_s(op, 2, token.c_str());
		cmd.erase(0, 2);

		//gasim suma pana la care o sa pastram cheltuieli
		token = cmd;
		int sum = stoi(token);

		if (strcmp(op, "<") == 0)
		{
			vector<Expense> expenses = this->service.getExpenses();
			vector<Expense> ::iterator it;
			for (it = expenses.begin(); it != expenses.end(); it++)
				if (strcmp((*it).getType(), type) != 0 || (*it).getSum() > sum)
					this->service.deleteExpense( (*it).getId() );
		}
		else if (strcmp(op, "=") == 0)
		{
			vector<Expense> expenses = this->service.getExpenses();
			vector<Expense> ::iterator it;
			for (it = expenses.begin(); it != expenses.end(); it++)
				if (strcmp((*it).getType(), type) != 0 || (*it).getSum() != sum)
					this->service.deleteExpense((*it).getId());
		}
	}

}

void UI::runUI()
{
	this->displayMenu();

	bool shouldRun = true;
	string cmd;

	while (shouldRun)
	{
		getline(cin, cmd);

		if (cmd.find("add") != string::npos)
			this->UIaddExpense(cmd);

		if (cmd.find("insert") != string::npos)
			this->UIinsertExpense(cmd);

		if (cmd.find("delete") != string::npos)
			this->UIdeleteExpense(cmd);

		if (cmd.find("show") != string::npos)
			this->UIgetExpenses(cmd);
		
		if (cmd.find("sum") != string::npos)
			this->UIsumExpense(cmd);

		if (cmd.find("max") != string::npos)
			this->UImaxExpense(cmd);

		if (cmd.find("sort") != string::npos)
			this->UIsortExpense(cmd);

		if (cmd.find("filter") != string::npos)
			this->UIfilterExpense(cmd);

		if (cmd.find("exit") != string::npos)
			shouldRun = false;
	}
}
