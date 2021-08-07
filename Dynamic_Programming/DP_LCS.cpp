#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int lcs(string s1, string s2, int m, int n, int *dp[]) {
	for (int i = 0; i < m + 1; i++) {
		dp[i][0] = 0;
	}
	for (int j = 0; j < n + 1; j++) {
		dp[0][j] = 0;
	}
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (dp[i][j] == -1) {
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = 1 + dp[i - 1][j - 1];
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				}
			} else {
				return dp[i][j];
			}
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

	string s1 = "ABDCJKERYFG";
	string s2 = "ABZZKRFGQPLM";
	int m = s1.length();
	int n  = s2.length();
	int *dp[m + 1];
	for (int i = 0; i < m + 1; i++) {
		dp[i] = new int[n + 1];
		for (int j = 0; j < n + 1; j++) {
			dp[i][j] = -1;
		}
	}
	int ans = lcs(s1, s2, m, n, dp);
	cout << ans;

	return 0;
}
