#include <bits/stdc++.h>
using namespace std;

int pow(int x, int n) {
	if (n == 0)
		return 1;
	int temp = pow(x, n / 2);
	temp *= temp;
	if (n & 1 != 0)
		return temp * x;
	else
		return temp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x = 5, n = -2;
	int ans = pow(x, n);
	if (n > 0)
		cout << ans;
	else
		cout << 1 / (double)ans;
}
//Not an eficient sol as fun call stack required.

//O/P
//0.04
