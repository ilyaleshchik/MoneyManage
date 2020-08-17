#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
#pragma once

typedef long long ll;
typedef long double ld;


class Viwer
{
private:
	string tableFile = "money.csv";
	string fullTable = "times.csv";
	vector<string> split(string& s);
	ld ToInt(string& s);

public:
	Viwer();
	~Viwer();
	void View(int day, int month, int year, string item);
};

