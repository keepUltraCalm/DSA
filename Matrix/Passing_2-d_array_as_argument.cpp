#include <iostream>
using namespace std;

void print(int *arr[], int m, int n) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << '\n';
	}
}

int main() {
	int m = 3, n = 3;
	int *arr[m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = j;
		}
	}
			print(arr, m, n);
			return 0;
		}
		//multi dim array c++
