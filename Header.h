#include <iostream>
#include <fstream>
#include <conio.h>
#pragma once
using namespace std;
struct p {
	double a, b;
	double coord;
	double x, y;

};
void show(p* mm, int n);
void vstavkami(p* mm, int n);
void bubble(p* mm, int n);
void shake(p* mm, int n);
void shell(p* mm, int n);
void Merge(p* mm, int first, int last);
void MergeSort(p* mm, int first, int last);
void quicksort(p* mm, int first, int last, int n);
void fill_the_matrix(int n, bool** m);
int counter();