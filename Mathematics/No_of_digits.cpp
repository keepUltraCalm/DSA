//Q...
//Count no. of digits

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
	cout << floor(log10(n) + 1);
	//quick way

	return 0;
}

//INPUT
//78590

//OUTPUT
//5
