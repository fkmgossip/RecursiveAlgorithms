#include <iostream>

using namespace std;

// Creating an Array

void fillRandomArray(int arr[], const int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}

// Array print

void print(int arr[], const int size) {

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

// Recursive option for finding the maximum of an Array

int max(int l, int r, int Arr[]) {

	int mid, n, v;
	if (l == r) {
		return Arr[l];
	}

	mid = (l + r) / 2;
	n = max(l, mid, Arr);
	v = max(mid + 1, r, Arr);
	cout << n << " Elem in array " << l << " " << mid << endl;
	cout << v << " Elem in array " << mid + 1 << " " << r << endl;
	if (n > v)
		return n;
	else return v;
}

// Hanoi towers

void put_disk(int n, char s1, char s2, char s3) {

	if (n == 1)
	{
		cout << s1 << " -> " << s3 << endl;
	}
	else
	{
			put_disk(n - 1, s1, s3, s2);
			cout << s1 << " -> " << s3 << endl;
			put_disk(n - 1, s2, s1, s3);
	}
}

// Knight's move

int try0(int i, int x, int y, int n, int a[], int b[], int **h) {
	
	int u, v, k = 0, q1 = 0;
	while (q1 == 0 && k < 8) {
		u = x + a[k];
		v = y + b[k];
		k++;
		if (u >= 0 && u<n && v>=0 && v<n)
			if (h[u][v] == 0) {
				h[u][v] = i;
				if (i < n * n && try0(i + 1, u, v, n, a, b, h) == 0) {
					h[u][v] = 0;
				}
				else q1 = 1;
			}
	}
	return q1;
}

// Queen placement

int check(int x[]) {

	for(int i=1; i<7;i++) {
		for (int j = i+1; j < 8; j++) {
			if (x[i] == x[j]) {
				return 0;
			}
		}
	}
	return 1;
}

void prn(int x[])
{
	for (int k = 1; k <= 7; k++)
		cout << x[k] << " ";
}
void try1(int i, int a[], int b[], int c[], int x[])
{
	for (int j = 1; j <= 7; j++)
		if (a[j] && b[i + j] && c[i - j + 7])
		{
			x[i] = j; a[j] = 0; b[i + j] = 0; c[i - j + 7] = 0;
			(i < 8) ? try1 (i + 1, a, b , c, x) : prn(x);
			a[j] = 1; b[i + j] = 1; c[i - j + 7] = 1;
			if (check(x)) {
				cout << endl;
				for (int i = 0; i < 8; i++) {
					cout << x[i] << " ";
				}
				cout << endl;
			}
		}
}

int main() {

	const int SIZE = 20;
	int Arr[SIZE];

	// Recursive option for finding the maximum of an Array

	fillRandomArray(Arr, SIZE);
	int maximum = max(0, SIZE - 1, Arr);
	print(Arr, SIZE);
	cout << endl;
	cout << maximum << endl;

	// Hanoi towers

	cout << "Enter count disk: ";
	int count_disk;
	cin >> count_disk;
	put_disk(count_disk, '1', '2', '3');

	// Knight's move

	int n = 5;
	int a[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	int b[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
	int** h = new int* [n]; 
	for (int i = 0; i < n; i++) {

		h[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			h[i][j] = 0;
		}
	}

	cout << "Enter x horse position: ";
	int x_horse_position;
	cin >> x_horse_position;
	cout << endl;
	cout << "Enter y horse position: ";
	int y_horse_position;
	cin >> y_horse_position;
	h[x_horse_position][y_horse_position] = 1;

	int q = try0(2, x_horse_position, y_horse_position, n, a, b, h);
	if (q)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << h[i][j] << " ";
			cout << endl;
		}
	}
	else cout << "No solution" << endl;

	// Queen placement

	int A[9] = {0, 1, 1, 1, 1, 1, 1, 1, 1};
	int B[17], c[15], x[9];
	for (int i = 0; i < 9; i++) x[i] = 1;
	for (int i = 2; i < 17; i++) B[i] = 1;
	for (int i = 0; i < 15; i++) c[i] = 1;
	try1(1, A, B, c, x);
}
