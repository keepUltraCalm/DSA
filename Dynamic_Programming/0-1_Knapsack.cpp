#include <bits/stdc++.h>
typedef long long ll;

using namespace std;


int dp_knapsack(int val[], int wt[], int n, int w) {
	int dp[n + 1][w + 1];
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = 0;
	}
	for (int i = 1; i <= w; i++) {
		dp[0][i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= w; j++) {
			if (wt[i - 1] > j) {
				dp[i][j] = dp[i - 1][j];
			} else {
				dp[i][j] = max(
				               dp[i - 1][j],
				               val[i - 1] + dp[i - 1][j - wt[i - 1]]
				           );
			}
		}
	}
	return dp[n][w];
}

// int knapsack(int val[], int wt[], int n, int w) {
// 	if (w == 0 || n == 0)
// 		return 0;
// 	if (wt[n - 1] > w)
// 		return knapsack(val, wt, n - 1, w);
// 	else
// 		return max(knapsack(val, wt, n - 1, w),
// 		           val[n - 1] + knapsack(val, wt, n - 1, w - wt[n - 1])
// 		          );
// }


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int val[] = {10, 40, 30, 50};
	int wt[] = {5, 4, 6, 3};
	int w = 10;
	int n = sizeof(wt) / sizeof(wt[0]);
	int ans = dp_knapsack(val, wt, n, w);
	cout << ans;


	return 0;
}
