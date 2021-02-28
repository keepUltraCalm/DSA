//Q..
//Iterative way of finding sum of digits of number


#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int sum_of_digits(int n) {
	int x = 0;
	/*we know when number becomes 0..we need not add it
	modulo 10..gives last digit of the number
	divide 10..removes last digit from number*/
	while (n > 0) {
		x += n % 10;
		n /= 10;
	}
	return x;
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

//theta(1)

