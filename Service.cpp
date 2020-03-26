#include "Service.h"
#include "Costs.h"

void Service::create_cost(int id, int day, int sum, char* type)
{
	Costs c(id, day, sum, type);
	this->r.create(c);
}	

Costs* Service::read_cost()
{
	return this->r.read();
}

void Service::update_cost(int id, int day, int sum, char* type,int new_id, int new_day, int new_sum, char* new_type)
{
	Costs c1(id, day, sum, type);
	Costs c2(new_id, new_day, new_sum, new_type);
	
	c1 = c2;
}

void Service::delete_cost(int id)
{
	for( int i=0 ; i<r.get_size ; i++)
		if (id == r.read()[i].get_id)
		{
			for (int j = i + 1; j < r.get_size; j++)
			{
				Costs aux = r.read()[j];
				r.read()[j] = r.read()[j-1];
				r.read[j - 1] = aux;
			}
			i = r.get_size;
		}
	r.get_size--;
}