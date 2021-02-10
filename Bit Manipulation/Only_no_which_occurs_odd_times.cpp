//Q...
//Only no. which occurs odd number of times in the array!!

//Brute
//just use a n^2 loop
//traverse through 2nd loop and check if
//arr[j]==arr[i]..count++
//check if count is odd or not

//Interesting Optimal Sol
// O(n)
//XOR Operator
//Useful Properties

// a^a = 0
// a^0 = a
// a^b = b^a
// a^(b^c) = (a^b)^c

// so what's the idea!!
// XOR complete array!
// how it works??
// xor of numbers appearing even times ==0
// ans^0 = ans

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//for input & output file

	int arr[] = {2, 3, 4, 4, 4, 3, 5, 5, 2};
	int n = sizeof(arr) / sizeof(arr[0]);

	int ans = arr[0];
	for (int i = 1; i < n; i++) {
		ans ^= arr[i];
	}
	cout << ans;

	return 0;
}

//Time complexity -> theta(1)

//INPUT
//2 3 4 4 4 3 5 5 2

//OUTPUT
//4
