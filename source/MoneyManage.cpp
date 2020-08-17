#include <iostream>
#include "Writer.h"
#include "Viwer.h"
using namespace std;


int main()
{
	Writer *wr = new Writer();
	Viwer *vr = new Viwer();
		


	bool run = 1;
	int command = 0;
	string s, date;
	ld p = 0;
	while (run)
	{
		system("cls");
		cerr << "1->Add\n2->View\n3->Exit\n";
		cin >> command;
		system("cls");
		if (command == 1)
		{
			cerr << "1)Item: ";
			cin >> s;
			cerr << "2)Price: ";
			cin >> p;
			cerr << "3)Date dd.mm.yy(id it's today type td): ";
			cin >> date;
			wr->Write(s, p, date);
		}
		else if (command == 2)
		{
			cerr << "1)Day(if u want all days type 0): ";
			int day = 0, month = 0, year = 0;
			string item = "-1";
			cin >> day;
			cerr << "2)Month(if u want all montes type 0): ";
			cin >> month;
			cerr << "3)Year(if u want all years type 0): ";
			cin >> year;
			cerr << "Item(if u wants all items type '-1'): ";
			cin >> item;
			vr->View(day, month, year, item);
		}
		else if (command == 3) run = 0;
	}


	delete wr;
	delete vr;
}
