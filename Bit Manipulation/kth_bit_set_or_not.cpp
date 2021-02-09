//Q...
//Check whether no. has kth bit set or not!!
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

	int n, k;
	cin >> n >> k;
	//if (n & (1 << (k - 1)) != 0) or we can write
	if ((n >> (k - 1)) & 1 == 1)
		// n=5, in binary is   101
		//right shift n (k-1) times...we get 010 -> 001
		// now and of last bit of 001 and 1 is 1
		cout << "Yes";
	else
		cout << "No";
	return 0;
}

//INPUT
//5 3

//OUTPUT
//Yes
