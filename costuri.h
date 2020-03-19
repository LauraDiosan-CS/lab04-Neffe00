#pragma once
#include <ostream>
using namespace std;

class Costs
{
	private:
		int day;
		int sum;
		char* type;
	public:
		Costs();
		Costs(int day, int sum, char* type);
		Costs(const Costs& c);
		~Costs();
		int get_day();
		int get_sum();
		char* get_type();
		void set_day(int day);
		void set_sum(int sum);
		void set_type(char* type);
		Costs& operator=(const Costs& c);
		bool operator==(const Costs& c);
		friend ostream& operator<<(ostream& os, const Costs& c);
};
