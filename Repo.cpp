#include "Repo.h"
#include <cstddef>

Repo::Repo()
{
	this->n = 0;
}

Repo::~Repo()
{
	this->n = 0;
}

int Repo::get_size()
{
	return this->n;
}
void Repo::create (Costs c)
{
	this->cost[this->n++] = c;
}
Costs* Repo::read()
{
	return this->cost;
}

void Repo::update(Costs c, Costs new_c)
{
	c = new_c;
}

void del(int id)
{
	for (int i = 0; i < n; i++)
		if (id == cost[i].get_id)
		{
			for (int j = i + 1; j < r.get_size; j++)
			{
				Costs aux = r.read()[j];
				r.read()[j] = r.read()[j - 1];
				r.read[j - 1] = aux;
			}
			i = r.get_size;
		}
	r.get_size--;
	

}
