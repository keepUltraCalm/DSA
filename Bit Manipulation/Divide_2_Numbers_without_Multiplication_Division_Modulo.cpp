//divide two numbers without division, multiplication, modulo
#include <bits/stdc++.h>
using namespace std;
int main() {
	int n = 14;
	int x = 0;
	//maintain a bool variable
	/*
	if any one is -ve...we will cout..-ans
	else
	ans

	also if taking -ve numbers maintain abs value of both
	*/
	if (x == 0) {

	} else {
		int temp = 0, q = 0, ans = 0;
		for (int i = 5; i >= 0; i--) {
			//i have taken 5 because in my numbers not more than 5 bits needed to represent
			if (temp + (x << i) <= n) {
				//apne aap subtract ho rhi h value
				//after doing for 8..now it will find for n-8 ke liye
				//3 se 0 tak i..let's see which satisfies this time
				temp += x << i;
				ans += 1 << i;
				//us value par le jao..add kr do ans mein..here 2^3 =8
			}
		}
		cout << ans;
	}

	return 0;
}


//O(logn)
//because n ko represent krne ke liye we need log2(n) + 1 bits..and we are traversing them

/*
ex 64
now 2^6 = 64
is 6 equal to log2(64)
2^0 bhi h..so total bits is 7
*/
