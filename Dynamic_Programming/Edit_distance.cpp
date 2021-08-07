#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int ed(string s1, string s2, int m, int n) {
	int dp[m + 1][n + 1];
	dp[0][0] = 0;
	for (int i = 1; i < m + 1; i++) {
		dp[i][0] = i;
	}
	for (int i = 1; i < n + 1; i++) {
		dp[0][i] = i;
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
		}
	}

	return dp[m][n];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1 = "CAT";
	string s2 = "CUT";
	int m = s1.length();
	int n = s2.length();
	int res = ed(s1, s2, m, n);
	cout << res;


	return 0;

}
