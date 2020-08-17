#include <iostream>
#include <fstream>
#include <vector>
#include "Writer.h"
#include <ctime>
#include <map>
#include <string>
using namespace std;

typedef long double ld;
typedef long long ll;


Writer::Writer(){}

Writer::~Writer(){}

void Writer::Write(string thing, ld price, string date)
{
	if (date == "td")
	{
		date = this->getTime();
	}
	
	for (char& c : thing)
	{
		if (c >= 'A' && c <= 'Z') c += 32;
	}


	ofstream fout(this->tableName, fstream::app);
	fout << date << ";" << thing << ";" << price << ";" << "\n";
	fout.close();

	ifstream fin(this->timeTable);
	string s;
	bool find = 0;
	vector<string> file;
	while (fin >> s)
	{
		vector<string> data(3, "");
		int lst = 0;
		for (char c : s)
		{
			if (c == ';') { lst++; continue; }
			data[lst] += c;

		}
		
		if (data[0] == date && thing == data[1])
		{
			ld cost = 0;
			find = 1;
			cost = atof(data[2].c_str());
			cost += price;
			data[2] = this->LdToStr(cost);
		}

		file.push_back(string(data[0] + ";" + data[1] + ";" + data[2] + ";"));
	}

	if (!find)
	{
		file.push_back(string(date + ";" + thing + ";" + this->LdToStr(price) + ";"));
	}

	fin.close();
	fout.open(this->timeTable);

	for (string cur : file)
	{
		fout << cur << "\n";
	}
	fout.close();
}

string Writer::LdToStr(ld& it)
{
	string res = "";
	res = to_string(it);
	return res;
}

string Writer::IntToStr(ll& it)
{
	string res = "";
	res = to_string(it);
	return res;
}

string Writer::getTime() 
{
	//getting a local time
	time_t t = time(0);
	tm* now = localtime(&t);
	string res = "";
	ll year = (now->tm_year + 1900);
	ll day = (now->tm_mday);
	ll month = (now->tm_mon + 1);
	if (day < 10)
		res += '0';
	res += this->IntToStr(day);
	res += ".";
	if (month < 10)
		res += "0";
	res += this->IntToStr(month);
	res += ".";
	res += this->IntToStr(year);
	return res;
}