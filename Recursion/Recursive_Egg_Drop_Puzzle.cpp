#include <bits/stdc++.h>
using namespace std;

int egg_puzz(int f, int e) {
	if (e == 0 || f == 0)
		return 0;
	if (e == 1  && f != 0)
		return f;
	if (f == 1 && e != 0)
		return 1;
	else {
		int ans = INT_MAX, curr = -1;
		for (int i = 1; i <= f; i++) {
			curr = 1 + max(egg_puzz(i - 1, e - 1), egg_puzz(f - i, e));
			if (curr < ans) {
				ans = curr;
			}
		}
		return ans;
	}
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int f = 10, e = 2;
	int res = egg_puzz(f, e);
	cout << res << "\n";

	return 0;
}
