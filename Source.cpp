#include <iostream>
#include <string>

using namespace std;
const int N = 6;

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

	friend void sort(Train A[]);
	string get_name() {
		return name;
	}
};
void sort(Train A[]) {
	int a, b, c;
	string d;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (A[j].hours > A[j + 1].hours) {
				a = A[j].number;
				b = A[j].hours;
				c = A[j].minutes;
				d = A[j].name;

				A[j].number = A[j + 1].number;
				A[j].hours = A[j + 1].hours;
				A[j].minutes = A[j + 1].minutes;
				A[j].name = A[j + 1].name;

				A[j + 1].number = a;
				A[j + 1].hours = b;
				A[j + 1].minutes = c;
				A[j + 1].name = d;
			}
			else if (A[j].hours = A[j + 1].hours && A[j].minutes > A[j + 1].minutes) {
				a = A[j].number;
				b = A[j].hours;
				c = A[j].minutes;
				d = A[j].name;

				A[j].number = A[j + 1].number;
				A[j].hours = A[j + 1].hours;
				A[j].minutes = A[j + 1].minutes;
				A[j].name = A[j + 1].name;

				A[j + 1].number = a;
				A[j + 1].hours = b;
				A[j + 1].minutes = c;
				A[j + 1].name = d;
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

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "ru");
	Train A[N];
	int a = 0;
	string name_1;

	system("pause");
	while (a != 4) {
		system("cls");
		cout << "Выберите действией:\n1.Ввод данных о 6-ти поездах\n2.Вывод на экран поездов, отсортированных по времени\n"
			"3.Вывод на экран информации о поездах, направляющихся в пункт, введенный с клавиатуры\n4.Выход из программы\n";
		cin >> a;
		switch (a) {
		case 1:
			for (int i = 0; i < N; i++) {
				system("cls");
				cout << "Поезд № " << i+1 << endl;
				cin >> A[i];
			}
			system("pause");
			break;
		case 2:
			system("cls");
			sort(A);
			cout << "Номер поезда\tПункт назначения\tВремя отправления\n";
			for (int i = 0; i < N; i++) {
				cout << A[i];
			}
			system("pause");
			break;
		case 3:
			system("cls");
			cin >> name_1;
			for (int i = 0; i < N; i++) {
				if (A[i].get_name() == name_1) {
					cout << "Номер поезда\tПункт назначения\tВремя отправления\n";
					cout << A[i];
				}
			}
			system("pause");
			break;
		case 4:
			system("cls");
			for (int i = 0; i < 100; i += rand() % 5 + 1) {
				cout << "Выход из программы:\n";
				cout << i << " %";
				system("cls");
			}
			system("pause");
			break;
		default:
			system("cls");
			cout << "Некорректный ввод, повторите!!!\n";
			system("pause");
		}
	}

	return 0;
}
