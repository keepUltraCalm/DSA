//Q...
//Check if no is a power of 2!!

//Brute
//we repeatedly divide  the number by 2 until
//it becomes 1..if at any point number becomes odd..
//it is not a power of 2

// edge case..if number given is 0(take care)

//so, what's the time complexity
// see..it traverse all bits so..we get theta(logn)

//Improving brute
//Use Brian Kerningam's Algo
//it will give us no. of set bits
//number which is power of 2 will have only 1 set bit
//so time complexity -> theta(1)

//Now, a one line sol

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool check(int n) {
	if (n == 0)
		return false;
	return (n & (n - 1) == 0);
}
//how it works!!
//we can unset the last set bit of a number
//by doing n & (n-1)
//now power of 2 has only 1 set bit
//so we should get 0 if the no. is power of 2 

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
	bool ans = check(n);
	cout << ans;

	return 0;
}

//Time complexity -> theta(1)

//INPUT
//5

//OUTPUT
//0
