#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <string>
#include <map>
using namespace std;

typedef long double ld;
typedef long long ll;



#pragma once
class Writer
{


private:
	string tableName = "money.csv";
	string timeTable = "times.csv";

private:
	string IntToStr(ll &it);
	string LdToStr(ld &it);
	string getTime();
public:
	Writer();
	~Writer();
	void Write(string thing, ld price, string date);
};

