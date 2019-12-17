#pragma once
#include <iostream>
#include <string>

using namespace std;

class Train {
private:
	string name;
	int number;
	int hours;
	int minutes;
public:
	Train() {
		name = '0';
		number = 0;
		hours = 0;
		minutes = 0;
		cout << "Вызван конструктор без параметров" << endl;
	}
	Train(string a, int b, int c, int d) {
		name = a;
		number = b;
		hours = c;
		minutes = d;
		cout << "Вызван конструктор с параметром" << endl;
	}
	Train(const Train& train) {
		name = train.name;
		number = train.number;
		hours = train.hours;
		minutes = train.minutes;
		cout << "Вызван конструктор копирования" << endl;
	}

	~Train() {
		cout << "Вызван деструктор" << endl;
	}

	friend istream& operator>> (istream& in, Train& train);
	friend ostream& operator<< (ostream& out, Train& train);
	Train& operator=(const Train& right);
	bool operator>(const Train& right);

	friend void sort(Train A[]);
	string get_name() {
		return name;
	}
};
