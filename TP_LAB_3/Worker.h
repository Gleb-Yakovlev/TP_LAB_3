#pragma once
 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Worker {
	string name;
	string surname;
	string phone;
	string address;
public:
	Worker();
	string getData(int);
	void setData(int, string);
	void ToFile(string, int);
	virtual int cash();
	virtual ~Worker();
	bool is_empty(ifstream&);
};