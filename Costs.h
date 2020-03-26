#pragma once
#include <ostream>
using namespace std;
/*
	Clasa Costs - cheltuiala
*/
class Costs
{
private:
/*
	Parametri privati
	In:	int id- id-ul
	int day- ziua din luna
	int sum- suma de bani
	char* type- tipul de cheltuiala
*/
	int id;
	int day;
	int sum;
	char* type;

public:
/*
	Metode publice
*/
	Costs();
	/*
		Constructor
	*/
	Costs(int id, int day, int sum, char* type);
	/*
		Constructor
		In:	int id- id-ul
		int day- ziua din luna
		int sum- suma de bani
		char* type- tipul de cheltuiala
	*/
	Costs(const Costs& c);
	/*
	Constructor
	conts Conts& c - obiect de tip conts
	*/
	~Costs();
	//destructor

	int get_id();
	//returneaza id-ul
	int get_day();
	//returneaza ziua
	int get_sum();
	//returneaza suma de bani
	char* get_type();
	//returneaza tipul de cheltuiala

	void set_id(int id);
	/*
		Modifica id-ul
		int id- id-ul
	*/
	void set_day(int day);
	/*
		Modifica ziua
		int day - ziua
	*/
	void set_sum(int sum);
	/*
		Modifica suma
		int sum - suma
	*/
	void set_type(char* type);
	/*
		Modifica tipul
		char* type - tipul de cheltuiala
	*/
	
	Costs& operator=(const Costs& c);
	bool operator==(const Costs& c);
	friend ostream& operator<<(ostream& os, const Costs& c);
};