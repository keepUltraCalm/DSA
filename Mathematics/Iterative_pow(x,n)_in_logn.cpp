//Q...
//Calculate x^n..brute n optimal!!

//Brute..
//loop from 1 to n..multiply x every time
//n==0..print 1
//n<0 make n +ve..x^n..divide by 1..
//need to take care of special overflow as -ve range is +1 of +ve


//Optimal sol
//Binary Exponentiation
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

	int x, n;
	cin >> x >> n;
	int res = 1;
	int p = n;
	if (n < 0)
		n = -n;

//so, what's the logic behind this stuff
// n, which is 5.. in binary can be written as 101
// suppose we have 4^10..or take anything
//it can be written in powers of 2..as..4^8 x 4^2
//another example..4^5 -> 4^4 x 4^1..1=2^0, 4=2^2
//now i can traverse every bit from least significant to most
//significant in logn time
	// now..just take the set bit and power it with x with corresponding value
	//of 2^0(for first)..as we will start from 0..
	//so for 4^5 -> 1     0     1
    //              2^2  2^1   2^0
    //so we get 4^(2^2) x 4^(2^0)
	
	while (n > 0) {
		if (n & 1)
			res = res * x;
		x = x * x;
		n = n >> 1;
	}
	if (p > 0)
		cout << res << "\n";
	else if (p < 0)
		cout << (float)1 / (float)res;
	else
		cout << "1";
	return 0;
}

//Time complexity -> O(logn)
//Space -> O(1)

//INPUT
//4 5

//OUTPUT
//1024

//INPUT
//4 -5

//OUTPUT
//0.000976562

//INPUT
//4 0

//OUTPUT
//1
