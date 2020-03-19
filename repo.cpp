#include "repo.h"
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
void Repo::add(Costs c)
{
	this->cost[this->n++] = c;
}
Costs* Repo::show()
{
	return this->cost;
}
