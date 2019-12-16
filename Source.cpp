#include <iostream>
#include <string>
#include "Train.h"

using namespace std;
const int N = 6;

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
				cout << "Поезд № " << i + 1 << endl;
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
