#include "Train.h"
const int N = 6;

void sort(Train A[]) {
	int a, b, c;
	string d;
	Train B;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (A[j].hours > A[j + 1].hours) {
				B = A[j];
				A[j] = A[j + 1];
				A[j + 1] = B;
			}
			else if (A[j].hours == A[j + 1].hours && A[j].minutes > A[j + 1].minutes) {
				B = A[j];
				A[j] = A[j + 1];
				A[j + 1] = B;
			}
		}
	}
}

istream& operator>>(istream& in, Train& train) {
	cout << "Введите пункт назначения поезда:\n";
	in >> train.name;
	system("cls");
	cout << "Введите номер поезда:\n";
	while (!(in >> train.number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Введите цифры, а не символы!!!\n";
	}

	while (1) {
		system("cls");
		cout << "Введите время отправления поезда (часы):\n";
		while (!(in >> train.hours)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите цифры, а не символы!!!\n";
		}
		if (train.hours >= 24) {
			cout << "Часы не могут быть более 24, введите снова\n";
			system("pause");
		}
		else
			break;
	}

	while (1) {
		system("cls");
		cout << "Введите время отправления поезда (минуты):\n";
		while (!(in >> train.minutes)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Введите цифры, а не символы!!!\n";
		}
		if (train.minutes >= 60) {
			cout << "Минуты не могут быть более 60, введите снова\n";
			system("pause");
		}
		else
			break;
	}

	return in;
}

ostream& operator<<(ostream& out, Train& train)
{
	if (train.hours < 10 && train.minutes < 10)
		out << train.number << "\t\t" << train.name << "\t\t\t" << "0" << train.hours << ":0" << train.minutes << endl;
	else if (train.hours < 10)
		out << train.number << "\t\t" << train.name << "\t\t\t" << "0" << train.hours << ":" << train.minutes << endl;
	else if (train.minutes < 10)
		out << train.number << "\t\t" << train.name << "\t\t\t" << train.hours << ":0" << train.minutes << endl;
	else
		out << train.number << "\t\t" << train.name << "\t\t\t" << train.hours << ":" << train.minutes << endl;
	return out;
}

Train& Train::operator=(const Train& right) {
		//проверка на самоприсваивание
		if (this == &right)
			return *this;

		this->number = right.number;
		this->hours = right.hours;
		this->minutes = right.minutes;
		this->name = right.name;

		return *this;
}
