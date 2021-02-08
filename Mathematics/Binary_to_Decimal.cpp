//Q...
//Binary to Decimal!!

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

	string s = "1001";
	int n = stoi(s, 0, 2);
	//multiply last bit with 2^0 and so on..
	cout << n;
}


//INPUT
//

//OUTPUT
//9
