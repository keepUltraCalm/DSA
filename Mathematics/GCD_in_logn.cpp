//Q...
//GCD of two numbers!!

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int gcd(int a, int b) {
//just to explain that parameters can be named anything..
//they can have diff name
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
	//optimized way rather than performing a-b everytime
	//if b>a
	//it will swap positions in first turn
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//for input & output file

	int n1, n2;
	cin >> n1 >> n2;
	int ans = gcd(n1, n2);
	cout << ans;

	return 0;
}

//Time complexity -> O(log(min(a,b)))
//Space -> O(1)

//INPUT
//12 15

//OUTPUT
//3
