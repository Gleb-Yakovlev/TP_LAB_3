#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "W_hourly_pay.h"
#include "W_interest_rate.h"
#include "W_on_staff.h"
using namespace std;


void file_output() {
    ifstream file("team.txt");
    if (!file) { cout << "FILE ERROR"; return; }
    cout << "WORKING TEAM" << endl;
    cout << "------------------------------------------------" << endl;
    string kost;
    int i = 0;
    while (!file.eof()) {
        i++;
        file >> kost;
        if (kost == " ") break;
        cout << i << ")Worker:" << endl;
        cout << kost << endl;
        file >> kost;
        cout << kost << endl;
        file >> kost;
        cout << kost << endl;
        file >> kost;
        cout << kost << endl;
        getline(file, kost);
        kost = " ";
    }

    file.close();
    cout << "------------------------------------------------" << endl;
    return;
}

void deleteInf() {
    ifstream file1("team.txt");
    if (!file1)
    {
        cout << "Uh oh, Sample.dat could not be opened!\n";
        return;
    }
    int size = 0;
    string ka;
    while (!file1.eof()) {
        getline(file1, ka);
        size++;
    }
    file1.close();

    ifstream file2("team.txt", ios::beg);
    string* array = new string[size];
    for (int i = 0; i < size; i++) {
        getline(file2, array[i]);
    }    
    file2.close();
    int sizeN = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == "") sizeN ++ ;
    }

    for (int i = 0; i != size-1 - sizeN + 1; i++) {
        if (array[i] == "") { for (int j = i; j < size - 1; j++) array[j] = array[j + 1]; i--; }
    }
    cout << "select a number" << endl;
    int k = 0;
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
    for (k--; k < size-1; k++) {
        array[k] = array[k + 1];
    }
    size--;
    ofstream filea;
    filea.open("team.txt", ios::trunc);
    for (int i = 0; i < size; i++) {
        filea << array[i] << endl;
    }
    filea.close();


    return;
}

int main()
{    
    Worker* obj = nullptr;


    while (1) {
        file_output();
        cout << "Select an order:" << endl;
        cout << "1 - Calculating salaries" << endl;
        cout << "2 - Deleting a worker" << endl;
        cout << "0 - Exit" << endl;
        int order = 0;
        int kost = 0;
        while (kost == 0)
        {
            cin >> order;
            if (cin.good() == false) {
                kost = 0;
                cout << "Incorrect input, try again" << endl;
                order = 0;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else kost = 1;
        }
        switch (order) {

        case 1: {
            int order2 = 0;
            cout << "Choose a salary type:" << endl;
            cout << "1 - Employee with hourly pay" << endl;
            cout << "2 - Employee in the state" << endl;
            cout << "3 - Employee with an interest rate" << endl;
            kost = 0;
            while (kost == 0)
            {
                cin >> order2;
                if (cin.good() == false) {
                    kost = 0;
                    cout << "Incorrect input, try again" << endl;
                    order2 = 0;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                else kost = 1;
            }
            switch (order2)
            {
            case 1: {
                if (!obj) delete obj;
                obj = new W_hourly_pay;
                system("cls");
                cout << "Worker salary:" << obj->cash() << endl;
                break; 
            }

            case 2: {
                if (!obj) delete obj;
                obj = new W_on_staff;
                system("cls");
                cout << "Worker salary:" << obj->cash() << endl;
                break;
            }

            case 3: {
                if (!obj) delete obj;
                obj = new W_interest_rate;
                system("cls");
                cout << "Worker salary:" << obj->cash() << endl;
                break;
            }

            default: {cout << "Wrong order" << endl; break; }

            }
            break;
        }

        case 2: {
            deleteInf();
            system("cls");
            break;
        }
        case 0: return 0;
        default: break;
        }
    }
}

