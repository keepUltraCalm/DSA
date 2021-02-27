//Q..
//To find sum of digits using recursion


#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

// a very easy ques to understand recursion!!
//all i want is..get the sum of last digits + sum of remaining digits
//if the number is 0 or becomes 0..return 0 from that function call

int sum_of_digits(int n) {
	if (n == 0) {
		return 0;
	}
	else {
		return sum_of_digits(n / 10) + n % 10;
	}
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


	int n = 12345;
	int ans = sum_of_digits(n);
	cout << ans;


	return 0;
}



//INPUT

//12345

//OUTPUT

//15


//Time complexity

// theta(d)
//d-> no. of digits

//Space

//theta(d)
//d+1 recursive calls in function call stack due to call for 0
