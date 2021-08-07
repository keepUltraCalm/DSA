#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int lcs(string s1, string s2, int m, int n) {

	if (m == 0 || n == 0)
		return 0;
	if (s1[m - 1] == s2[n - 1])
		return 1 + lcs(s1, s2, m - 1, n - 1);
	else {
		return max(lcs(s1, s2, m, n - 1),
		           lcs(s1, s2, m - 1, n)
		          );
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1 = "ABCDGH";
	string s2 = "AEDFHR";
	int m = s1.length();
	int n = s2.length();
	int ans = lcs(s1, s2, m, n);
	cout << ans;


	return 0;

}
