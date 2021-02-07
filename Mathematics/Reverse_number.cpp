//Q...
//Reverse an integer

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
	reverse(s.begin(), s.end());
	//to reverse the string
	int z = stoi(s);
	//to convert string to int
	cout << z;

	return 0;
}

//INPUT
//12345

//OUTPUT
//54321

//Bonus
//learn stl to increase efficiency!!
