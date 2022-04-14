#include <iostream>
#include <string>
using namespace std;

struct Work
{
	string name;
	string surname;
	int birth;
	string position;
	int earn;
};

int main()
{
	int i;
	int b;
	int sum=0;

	Work people[8] = { {"Nikita", "Li", 2003, "student", 3000},
	{"Nelli","Shevchenko",1968,"teacher", 15000},
	{"Ilya","Avilov",1989,"reactor",50000},
	{"Artem","Prokopec",1988,"Programmer",200000},
	{"Nikita","Kokorovich",1994,"architect",50000},
	{"Kostya","Shevchenko",1996,"soulder",30000},
	{"Ovik","Saakyan",1995,"hydraulic engineer",700000},
	{"Oleg","Minov",1999,"Designer",99990} };

	for (i = 0; i < 8; i++) {


		sum += people[i].earn;
		b = sum / 8;
	}

	{
		cout << b << "\n";
	}

	for (i = 0; i < 8; i++) {
		if (2022 - people[i].birth > 30)
			cout << people[i].name << endl;
		cout << "\n";
	}
	return 0;
}

