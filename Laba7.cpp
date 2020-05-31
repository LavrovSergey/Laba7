#include <iostream>
#include <fstream>
#include <conio.h>
#include "Header.h"
using namespace std;

int menu_start() {
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 7) % 7;
		if (key == 0) cout << "-> Вставками" << endl;
		else  cout << "   Вставками" << endl;
		if (key == 1) cout << "-> Пузырьком" << endl;
		else  cout << "   Пузырьком" << endl;
		if (key == 2) cout << "-> Перемешиванием" << endl;
		else  cout << "   Перемешиванием" << endl;
		if (key == 3) cout << "-> Быстрое" << endl;
		else  cout << "   Быстрое" << endl;
		if (key == 4) cout << "-> Слиянием" << endl;
		else  cout << "   Слиянием" << endl;
		if (key == 5) cout << "-> Шелла" << endl;
		else  cout << "   Шелла" << endl;
		if (key == 6) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int main(bool isRunning)
{
	setlocale(LC_ALL, "Russian");
	int n, x2, y2, x1, y1;
	int pnt = 0;
	n = counter();
	p* mm = new p[n * (n - 1) / 2];
	bool** m = new bool* [n];
	for (int i = 0; i < n; i++)
	{
		m[i] = new bool[n];
	}
	fill_the_matrix(n, m);
	cout << "Заполните координаты точек между собой" << endl;
	p* mas1 = new p[n];
	for (int i = 0; i < n; i++) {
		cout << i + 1 << " x:";
		cin >> mas1[i].x;
		cout << i + 1 << " y:";
		cin >> mas1[i].y;
	}
	bool** used = new bool* [n] {false};
	for (int i = 0; i < n; i++)
	{
		used[i] = new bool[n] {false};
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (m[i][j]) {
				used[i][j] = true;
				if ((used[j][i] && !used[i][j]) || (!used[j][i] && used[i][j])) {
					mm[pnt].a = i + 1;
					mm[pnt].b = j + 1;
					mm[pnt].coord = (mas1[j].x - mas1[i].x) / 2+(mas1[j].y - mas1[i].y) / 2;
					pnt++;
					used[j][i] = true;
				}
			}
	}
	isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu_start();
		switch (answer)
		{
		case 0:vstavkami(mm, pnt);  break;
		case 1:bubble(mm, pnt); break;
		case 2:shake(mm, pnt);; break;
		case 3:quicksort(mm, 0, pnt - 1, pnt); show(mm, n-1); break;
		case 4:MergeSort(mm, 1, pnt); show(mm, n);cout<<"понятия не имею откуда береться лишнее"; break;
		case 5:shell(mm , pnt); break;
		case 6: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}
	return 0;
}
