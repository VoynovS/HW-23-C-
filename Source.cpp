#include <iostream> 
#include <stdlib.h> 
#include <time.h> 
#include <algorithm>
using namespace std;
//Task 1
void funcMax(int& a, int& b, int& c);
//Task 2
int random(int array[], int length);
void showArr(int array[], int lenght);
int arr1(int arr[], int length);
//Task 3
void change(int array[], int length, int array2[], int length2);
int random10(int array[], int length);

int main() {

	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "Task 1.\nEnter 3 numbers:\n";
	int a, b, c;
	cin >> a >> b >> c;
	funcMax(a, b, c);
	cout << a << " " << b << " " << c << endl;

	cout << "Task 2.\n";
	int arr[10];
	random(arr, 10);
	cout << "General array: ";
	showArr(arr, 10);
	cout << arr1(arr, 10) << endl;

	cout << "Task 3.\n";
	cout << "First general array:  ";
	int arr1[10];
	int arr2[10];
	int* pArr1 = &arr1[0];
	int* pArr2 = &arr2[0];
	random10(pArr1, 10);
	random10(pArr2, 10);
	showArr(pArr1, 10);
	cout << "Second general array: ";
	showArr(pArr2, 10);
	change(pArr1, 10, pArr2, 10);
	cout << "Ready array: ";
	showArr(pArr2, 10);

	return 0;
}

//Task 3
int random10(int array[], int length) {
	for (int i = 0; i < length; i++)
		*(array + i) = rand() % 10 + 1;
	return array[length];
}

void change(int array[], int length, int array2[], int length2) {
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length2; j++) {
			if (*(array + i) == *(array2 + j))
				*(array2 + j) = 0;
		}
}
//Task 2
int random(int array[], int length) {
	for (int i = 0; i < length; i++)
		*(array + i) = rand() % (100 - (-100) + 1) - 100;
	return array[length];

}

void showArr(int array[], int lenght) {
	cout << "[";
	for (int i = 0; i < lenght; i++)
		cout << *(array + i) << ", ";
	cout << "\b\b]\n";
}

int arr1(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		if (*(arr + i) < 0) {
			int& refi = *(arr + i);
			return refi;
		}
	}
	int& refi2 = *(arr + 0);
	return refi2;
}

//Task 1
void funcMax(int& a, int& b, int& c) {
	if (a > b && a > c)
		c = b = a;
	else
		if (b > c && b > a)
			a = c = b;
		else
			a = b = c;
}