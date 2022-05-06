#include <iostream>
#include <string>
#include "W_hourly_pay.h"
using namespace std;

int W_hourly_pay::cash()
{
	return hours * traf;
}

W_hourly_pay::~W_hourly_pay()
{
	ofstream out("team.txt");
	out << getData(1) << " " << getData(2) << " " << getData(3) << " " << getData(4) << " " << hours << " " << traf;
	out.close();
}

W_hourly_pay::W_hourly_pay()
{
	ifstream in("team.txt");
	string callback;
	int flag;
	cout << "Enter manually or download from a file? 1/0" << endl;

	int kost = 0;
	while (kost == 0)
	{
		cin >> flag;
		if (cin.good() == false || flag != 0 && flag != 1) {
			kost = 0;
			cout << "Incorrect input, try again" << endl;
			flag = 0;
			cin.clear();
			cin.ignore(100, '\n');
		}
		else kost = 1;
	}

	if (!flag)
	{
		if (!in || is_empty(in))
		{
			cout << "The File is Empty" << endl;
			system("pause");
			flag = 1;
		}
	}
	if (flag)
	{
		system("cls");
		cout << "Enter Name" << endl;
		cin >> callback;
		setData(1, callback);
		ToFile(callback, 1);
		cout << "Enter Surname" << endl;
		cin >> callback;
		setData(2, callback);
		ToFile(callback, 1);
		cout << "Enter phone" << endl;
		cin >> callback;
		setData(3, callback);
		ToFile(callback, 1);
		cout << "Enter address" << endl;
		cin >> callback;
		setData(4, callback);
		ToFile(callback, 0);
		cout << "Enter the number of hours" << endl;
		cin >> hours;
		cout << "Enter the price per hour of work" << endl;
		cin >> traf;
	}
	else
	{
		cout << "Select a number" << endl;
		int k = 0;
		string k2;

		int kost = 0;
		while (kost == 0)
		{
			cin >> k;
			if (cin.good() == false) {
				kost = 0;
				cout << "Incorrect input, try again" << endl;
				k = 0;
				cin.clear();
				cin.ignore(100, '\n');
			}
			else kost = 1;
		}

		for (int i = 0; i < k - 1; i++) {
			getline(in, k2);
			if (in.eof()) {
				cout << "FATAL ERROR" << endl;
				return;
			}
		}
		in >> callback;
		setData(1, callback);
		in >> callback;
		setData(2, callback);
		in >> callback;
		setData(3, callback);
		in >> callback;
		setData(4, callback);
		cout << "Enter the number of hours" << endl;
		cin >> hours;
		cout << "Enter the price per hour of work" << endl;
		cin >> traf;
	}
	in.close();
}
