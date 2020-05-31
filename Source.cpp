#include "Header.h"
#include<iostream>
#include <fstream>
using namespace std;

void show(p* mm, int n) {
	for (int i = 0; i < n; i++) {
		cout << mm[i].a << "--" << mm[i].b << endl;
	}
	system("pause");
}
void vstavkami(p* mm, int n) {
	p temp;
	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0 && mm[j - 1].coord > mm[j].coord; j--)
		{
			swap(mm[j - 1], mm[j]);
		}
	}
	show(mm, n);
}
void bubble(p* mm, int n) {
	p temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (mm[j].coord > mm[j + 1].coord) {
				temp.coord = mm[j].coord;
				temp.a = mm[j].a;
				temp.b = mm[j].b;
				mm[j].coord = mm[j + 1].coord;
				mm[j].b = mm[j + 1].b;
				mm[j].a = mm[j + 1].a;
				mm[j + 1].coord = temp.coord;
				mm[j + 1].a = temp.a;
				mm[j + 1].b = temp.b;
			}
		}
	}
	show(mm, n);
}
void shake(p* mm, int n) {
	p temp;
	int left = 1;
	int right = n - 1;
	while (left <= right) {
		for (int i = right; i >= left; i--)
			if (mm[i - 1].coord > mm[i].coord)
			{
				temp.coord = mm[i].coord;
				temp.a = mm[i].a;
				temp.b = mm[i].b;
				mm[i].coord = mm[i - 1].coord;
				mm[i].b = mm[i - 1].b;
				mm[i].a = mm[i - 1].a;
				mm[i - 1].coord = temp.coord;
				mm[i - 1].a = temp.a;
				mm[i - 1].b = temp.b;
			}
		left++;

		for (int i = left; i <= right; i++)
			if (mm[i - 1].coord > mm[i].coord)
			{
				temp.coord = mm[i].coord;
				temp.a = mm[i].a;
				temp.b = mm[i].b;
				mm[i].coord = mm[i - 1].coord;
				mm[i].b = mm[i - 1].b;
				mm[i].a = mm[i - 1].a;
				mm[i - 1].coord = temp.coord;
				mm[i - 1].a = temp.a;
				mm[i - 1].b = temp.b;
			}
		right--;

	}
	show(mm, n);
}
void shell(p* mm, int n) {
	int i, j, d;
	p temp;
	d = n / 2;
	while (d > 0) {
		for (i = 0; i < n - d; i++) {
			j = i;
			while (j >= 0 && mm[j].coord > mm[j + d].coord) {
				temp.coord = mm[j].coord;
				temp.a = mm[j].a;
				temp.b = mm[j].b;
				mm[j].coord = mm[j + d].coord;
				mm[j].b = mm[j + d].b;
				mm[j].a = mm[j + d].a;
				mm[j + d].coord = temp.coord;
				mm[j + d].a = temp.a;
				mm[j + d].b = temp.b;
				j--;
			}
		}
		d = d / 2;
	}
	show(mm, n);
}
void Merge(p* mm, int first, int last){
	int middle, start, final, j;
	p* mas = new p[100];
	middle = (first + last) / 2;
	start = first;
	final = middle + 1;
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (mm[start].coord < mm[final].coord))) {
			mas[j].coord = mm[start].coord;
			mas[j].a = mm[start].a;
			mas[j].b = mm[start].b;
			start++;
		}
		else {
			mas[j].coord = mm[final].coord;
			mas[j].a = mm[final].a;
			mas[j].b = mm[final].b;
			final++;
		}
	for (j = first; j <= last; j++) {
		mm[j].coord = mas[j].coord;
		mm[j].a = mas[j].a;
		mm[j].b = mas[j].b;
	}
	delete[]mas;
}
void MergeSort(p* mm, int first, int last) {
	if (first < last) {
		MergeSort(mm, first, (first + last) / 2);
		MergeSort(mm, (first + last) / 2 + 1, last);
		Merge(mm, first, last);
	}
}
void quicksort(p* mm, int first, int last, int n){
	p mid, temp;
	int f = first, l = last;
	mid.coord = mm[(f + l) / 2].coord;
	mid.a = mm[(f + l) / 2].a;
	mid.b = mm[(f + l) / 2].b;
	mid.x = mm[(f + l) / 2].x;
	mid.y = mm[(f + l) / 2].y;
	do
	{
		while (mm[f].coord < mid.coord) f++;
		while (mm[l].coord > mid.coord) l--;
		if (f <= l) {
			temp.coord = mm[f].coord;
			temp.a = mm[f].a;
			temp.b = mm[f].b;
			mm[f].coord = mm[l].coord;
			mm[f].b = mm[l].b;
			mm[f].a = mm[l].a;
			mm[l].coord = temp.coord;
			mm[l].a = temp.a;
			mm[l].b = temp.b;
			f++;
			l--;
		}
	} while (f < l);
	if (first < l)quicksort(mm, first, l, n);
	if (f < last)quicksort(mm, f, last, n);
}
void fill_the_matrix(int n, bool** m) {
	int a;
	ifstream f("txt.txt");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			f >> a;
			if (a == 0) {
				m[i][j] = 0; cout << m[i][j] << " ";
			}
			else if (a == 1) {
				m[i][j] = 1; cout << m[i][j] << " ";
			}

		}
		cout << endl;
	}
}

int counter() {
	char a = ' ';
	int n = 0;
	int pnt = 0;
	ifstream f("txt.txt");
	while (a != '\n') { f.get(a); if (isdigit(a)) n++; }
	f.close();
	return n;
}
