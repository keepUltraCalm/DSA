#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int lis(int arr[], int n) {
	int dp[n] = {1};//kyuki har element ka filhal lis to 1 hoga hi na
	for (int i = 1; i < n; i++) {//ye to h dp array traverse krne ke liye..har element
		int ans = 0;//ye rhegi max value jo prev elements se milegi
		for (int j = 0; j < i; j++) {//ye curr ke peeche vaale elements
			if (arr[j] < arr[i] && dp[j] > ans) {//prev elements chote hone chahiye +
				//ans mein tabhi to assign krega jab usse bda hoga..
				//kyuki ans mein maximum hoga after this iteration
				ans = dp[j];
			}
		}
		dp[i] = ans + 1;//kyuki ab uss current element ko bhi to include krega
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (dp[i] > max)
			max = dp[i];
	}
	return max;//max nikalo ab array ka vhi ans h

}


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {3, 4, 2, 8, 10, 5, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	int ans = lis(arr, n);
	cout << ans;


	return 0;

}
