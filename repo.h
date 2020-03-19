#pragma once
#include "costuri.h"

class Repo
{
	private:
		Costs cost[1000];
		int n;
	public:
		Repo();
		~Repo();
		void add(Costs c);
		Costs* show();
		int get_size();
};

