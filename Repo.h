#pragma once
#include "Costs.h"
//clasa de tip repo pentru cheltuieli
class Repo
{
private:
	Costs cost[100];
	//vectorul unde se memoreaza obiectele
	int n;
	//numarul de obiecte
public:
	Repo();//constructr
	~Repo();//destructor

	void create(Costs c);
	/*
		Adauga un obiect de tip cheltuiala
		Costs c - obiect de tip cheltuiaal
	*/
	Costs* read();
	/*
		Afiseaza toate obiecte de tip cheltuiala
	*/
	void update(Costs c, Costs new_c);
	/*
		Modifica un obiect de tip cheltuiala
		int id - id-ul
		Costs c - obiect-ul modificat de tip cheltuiaal
	*/
	void del(int id);
	/*
		Sterge un obiect de tip cheltuiala
		int id - id-ul
	*/
	int get_size();
	/*
		Returneaza numarul de obiecte
	*/	
};