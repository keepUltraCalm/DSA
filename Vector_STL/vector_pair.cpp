#include <bits/stdc++.h>
using namespace std;
int main() {
	int a[] = {10, 15, 5};
	char b[] = {'X', 'Y', 'Z'};
	pair<int, char> c[3];
	for (int i = 0; i <= 2; i++) {
		c[i] = make_pair(a[i], b[i]);
	}
	sort(c, c + 3);
	for (int i = 0; i < 3; i++) {
		cout << c[i].first << " " << c[i].second << '\n';
	}
	return 0;
}
