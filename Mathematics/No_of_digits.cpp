//Q...
//Check if no. is palindrome !!

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

	int n;
	cin >> n;
	string s = to_string(n);
	//converts int to string
	int low = 0;
	int high = s.length() - 1;
	bool res  = true;
	while (low < high) {
		if (s[low] != s[high]) {
			res = false;
			break;
		}
		low++;
		high--;
	}
	if (res)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}
