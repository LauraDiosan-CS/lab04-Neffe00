#pragma once
#include "Repo.h"
#include "Costs.h"
/*Clasa Service
*/
class Service
{
private:
	Repo& r;
	
public:
	//Constructor
	Service(){}
	//Constructor
	Service(Repo& repo) :r{ repo } {
	}

	void create_cost( int id, int day, int sum, char* type );
	/*
		Desc: Functia creaza un obiect de tip cheltuiala
		In:	int id- id-ul
			int day- ziua din luna
			int sum- suma de bani
			char* type- tipul de cheltuiala
	*/
	Costs* read_cost();
	/*
		Desc: Functia returneaza toate cheltuiele
		Out: Toate cheltuielile
	*/
	void update_cost(int id, int day, int sum, char* type, int new_id, int new_day, int new_sum, char* new_type);
	/*
		Desc: Functia modifica un obiect de tip cheltuiala
		In:	int id- id-ul
			int day- ziua din luna
			int sum- suma de bani
			char* type- tipul de cheltuiala
			int new_id- noul id-ul
			int new_day- noua ziua din luna
			int new_sum- noua suma de bani
			char* new_type- noul tipul de cheltuiala
	*/
	void delete_cost(int id);
	/*
		Desc: Functia sterge un obiect de tip cheltuiala
		In:	int id- id-ul
			int day- ziua din luna
			int sum- suma de bani
			char* type- tipul de cheltuiala
	*/
};