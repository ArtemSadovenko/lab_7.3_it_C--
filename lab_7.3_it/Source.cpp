#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

void create(int** a, int col, int row, int l, int h);
void print(int** a, int row, int col);
int count(int** a, int row, int col);
void num(int** a, int row, int col, int& j_max);

void main() {
	srand((unsigned)time(NULL));

	int k;
	int n;

	cout << "row = "; cin >> k;
	cout << "col = "; cin >> n;

	int l = 0;
	int h = 2;

	int max = 0;
	int q;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	create(a, n, k, l, h);

	print(a, k, n);

	q = count(a, k, n);
	cout << "num = " << q << endl;

	num(a, k, n, max);
	cout <<"j_max = " << max + 1 << endl;

	
}

void create(int** a, int col, int row, int l, int h) {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			a[i][j] = l + rand() % (h - l + 1);
}

void print(int** a, int row, int col) {
	for (int i = 0; i < row; i++) {
		cout << "|";
		for (int j = 0; j < col; j++) {
			cout << setw(4) << a[i][j] << " ";
		}
		cout << "|" << endl;
	}
	cout << endl;
}

int count(int** a, int row, int col) {
	int p = 0;
	for (int i = 0; i < row; i++) {
		int u = 0;
		for (int j = 0; j < col; j++) {
			if (a[i][j] == 0) {
				p++;
				break;
			}
		}
	}
	return p;
}

void num(int** a, int row, int col,  int& j_max) {
	int a_same = a[0][0]+1;
	int mp = 0;
	int max = 0;
	for (int j = 0; j < col; j++) {
		for (int i = 0; i < row; i++) {
			if (a[i][j] == a_same) {
				mp += 1;
				
				if (mp > max) {
					max = mp;
					j_max = j;
				}
			}
			else {
				a_same = a[i][j];
				mp = 0;
			}
		}
		a_same = a[0][j+1]+1;
		mp = 0;
	}
}