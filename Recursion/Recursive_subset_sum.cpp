//count no. of subsets with given sum in an array

#include <bits/stdc++.h>
using namespace std;

int count_subsets(int arr[], int n, int sum) {
	if (n == 0) {
		if (sum == 0)
			return 1;
		else
			return 0;
	}
	return count_subsets(arr, n - 1, sum) +
	       count_subsets(arr, n - 1, sum - arr[n - 1]);
  //sum of either take it..or not take it
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int arr[] = {10, 10, 15};
	int sum = 25;
	int n = sizeof(arr) / sizeof(arr[0]);
	int s = count_subsets(arr, n, sum);
	cout << s;

}

//O/P
//2

//Not an optimal solution 
//Time complexity
//O((2^n for last level) + ((2^n)-1)for internal nodes)
