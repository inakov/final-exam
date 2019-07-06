#include<iostream>
#include <cmath>
using namespace std;

int getNumLenght(int a) {
	if (a == 0) {
		return 1;
	}

	int left = a;
	int size = 0;
	while (left > 0) {
		size++;
		left /= 10;
	}

	return size;
}

int min(int a, int b) {
	return a < b ? a : b;
}

int cmpLex(int a, int b) {
	int sizeA = getNumLenght(a);
	int sizeB = getNumLenght(b);
	int minSize = min(sizeA, sizeB);

	for (int i = 1; i <= minSize; i++) {
		int nextNumberFromA = a / pow(10, (sizeA - i));
		int nextNumberFromB = b / pow(10, (sizeB - i));
		cout << nextNumberFromA << " ? " << nextNumberFromB << endl;
		if (nextNumberFromA > nextNumberFromB) {
			return -1;
		} else if (nextNumberFromA < nextNumberFromB) {
			return 1;
		}
	}	
	
	return 0;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void sort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (cmpLex(array[j], array[j + 1]) < 0) swap(array[j], array[j + 1]);
		}
	}

	for (int i=0; i<6; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}


int main() {
	int arr[] = {14, 13, 78, 7, 2018, 9, 0};
	sort(arr, 7);
}
