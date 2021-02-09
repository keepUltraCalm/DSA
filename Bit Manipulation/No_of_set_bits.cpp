//Q...
//Count number of set bits!!

//Brute
//int count=0;
// while(n>0){
//if(n&1==1)
//	count++;
//n=n>>1;
//}

//Time complexity -> theta(no. of bits)

//So can we do better??
//Yes..

//Brian Kerningam's Algo

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
	int ans = 0;
	while (n > 0) {
		n = n & (n - 1);
//so how is this magic happening that we get
//below time complexity
//the logic is that is i do and of n,n-1
//i can change the last set bit to 0 without changing anything else
//for ex;;

		//40 -> 101000
		//39 -> 100111 (the bits after last set bit along with it reversed)
		//on and
		// we get 100000 i.e., 32

		ans++;
	}
	cout << ans;

	return 0;
}

//Time complexity -> theta(no. of set bit count)

//INPUT
//40

//OUTPUT
//2
