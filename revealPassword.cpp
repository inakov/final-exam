#include<iostream>
#include<vector>

using namespace std;

const int MAX_ROW = 20;
const int MAX_COL = 30;
const int MAX_TITLE = 100;

bool isRowSorted(char bookRow[MAX_COL][MAX_TITLE], int col) {
	for (int i = 0; i < col - 1; i++) {
		if (strcmp(bookRow[i], bookRow[i + 1]) > 0)
			return false;
	}

	return true;
}

void revealPassword(char books[MAX_ROW][MAX_COL][MAX_TITLE], int rows, int cols) {
	for (int i = 0; i < rows; i++ ) {
		for (int j = 0; j < cols; j++) {
			cout << books[i][j] << " ";
		}
		cout << endl;
	}
	
	vector<int> password;
	const int midCol = cols / 2;
	for (int i = 0; i < rows; i++) {
		if (isRowSorted(books[i], cols)) {
			char* title = books[i][midCol];

			int passDigit = 0;
			for (int nextCharIndex = 0; nextCharIndex < MAX_TITLE; nextCharIndex++) {
				char nextChar = title[nextCharIndex];
				if (nextChar == '\0') {
					password.push_back(passDigit);
					passDigit = 0;
					break;
				}

				if (nextChar == ' ') {
					password.push_back(passDigit);
					passDigit = 0;
					continue;
				}
				passDigit++;
			}
		}
	}

	for(int i=0; i < password.size(); i++) {
		cout << password.at(i) << ' ';
	}
	cout << endl;
}

int main() {
	char books[MAX_ROW][MAX_COL][MAX_TITLE] = {
		{"Abc", "Bcd Aldi Pederas", "Cde"},
		{"Bcd", "Abc Da mu go tura", "Cde"},
		{"Bfg", "Efg", "Isn"}
	};

	revealPassword(books, 3, 3);

	return 0;
}
