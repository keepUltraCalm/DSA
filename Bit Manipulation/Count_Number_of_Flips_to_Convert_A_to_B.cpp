//no of flips to make the numbers same
#include <bits/stdc++.h>
using namespace std;
int main() {
	int a = 10;
	int b = 20;
  // a ->  00001010
  // b ->  00010100
  //xor gives  00011110
	int ans = a ^ b;
  //xor will give me the set bits on its correct places
  //where both numbers bits differ
  //and then i can use count set bits
	int res = 0;
	while (ans > 0) {
		ans = ans & (ans - 1);
		++res;
	}
	cout << res;

	return 0;
}

/*
O/P
4
*/
