#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "Viwer.h"
using namespace std;

typedef long long ll;
typedef long double ld;

Viwer::Viwer() {}
Viwer::~Viwer() {}


vector<string> Viwer::split(string& s) 
{
	vector<string> res(3);
	int lst = 0;

	for (char& c : s)
	{
		if (c == ';') { lst++; continue; }
		res[lst] += c;
	}
	return res;
}

ld Viwer::ToInt(string& s)
{
	ld res = 0.0;
	char *p;
	res = atof(s.c_str());
	return res;
}


void Viwer::View(int day, int month, int year, string item = "-1") 
{
	system("cls");
	bool isAllDays = 0, isAllMonth = 0, iaAllYears = 0, isAllItems = 0;
	if (day == 0)
		isAllDays = 1;
	if (month == 0)
		isAllMonth = 1;
	if (year == 0)
		iaAllYears = 1;
	if (item == "-1")
		isAllItems = 1;

	for (char& c : item)
	{
		if (c >= 'A' && c <= 'Z') c += 32;
	}

	ifstream fin("times.csv");
	string s;
	map<string, ld> cnt;
	while (fin >> s)
	{
		vector<string> data = this->split(s);

		vector<int> date(3, 0);
		int lst = 0;			
		for (char& c : data[0])
		{
			if (c == '.') { lst++; continue; }
			date[lst] *= 10;
			date[lst] += (c - '0');
		}
		if ((date[0] == day || isAllDays) && (date[1] == month || isAllMonth) && (date[2] == year || iaAllYears) && (data[1] == item || isAllItems))
		{
			cnt[data[1]] += this->ToInt(data[2]);
		}
	}
	

	for (auto it : cnt)
	{
		cout << it.first << "->" << it.second << "\n";
	}
	int x;
	system("pause");
	fin.close();
}
