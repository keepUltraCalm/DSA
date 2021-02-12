//Q...
//What if we get ques as...find exactly the two no.'s which occur
//odd number of times in the array!!

//The brute force approach

// ok..so we need to find those two numbers..right
// so we just use a n^2 loop
//check if arr[i]==arr[j]
//increase count,check if it is odd or even
//if odd..we print the number


//so..is there any better way..
//yes..there is
//now, its a real hard and tricky problem!!




//Optimal sol

//so first..we xor all the numbers..
//and we get something..now what is that something??
//that is the xor of our answers!!
//3, 4, 3, 4, 8, 4, 4, 32, 7, 7..if that's the array..
//even occuring will cancel each other..so we are left with
//8^32....which will give us 40..and 8 and 32 are my answers
//but i have only 40

// now what is the property of xor
// it gives 1 only when we have 1 and 0
// now ..what is the binary of 40..
// lets see 8  ->  0 0 1 0 0 0
//          32 ->  1 0 0 0 0 0

//xor i.e., 40 ->  1 0 1 0 0 0
//now look at the last set bit(it will always have it)
// so now, i can say that the 4th bit(start from last) of the two numbers
// are different..see above example

// now if i can somehow get a number which has only the 4th bit set(int this example)
// i can get my ans..let's see how

// first we need to get the required no
// so for that we use... xor & ~(xor-1)...
//now..how does this work!!

// we have  40  ->  1 0 1 0 0 0
//now 40-1  39  ->  1 0 0 1 1 1
//(you can reverse all bits after last set bit including it to get n-1 )
// ~39.....which means reverse all bits in 39..
// which gives us   0 1 1 0 0 0

//now lets see the & of 40 and ~39
// 40  ->   1 0 1 0 0 0
// ~39 ->   0 1 1 0 0 0  do and

//          0 0 1 0 0 0
//the result is a number whose set bit is the last set bit of the original number i.e., 40 here


//now, what can i do with this??

// see..all the numbers in the array will have this position bit either 1 or 0
// so i can create two different groups...and i know for sure that both the answers will
//come in different groups..for that reason..we have done so much stuff!!

//now just xor everything according to their groups..and get the answers😎

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

	int arr[] = {3, 4, 3, 4, 8, 4, 4, 32, 7, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	int XOR = 0, res1 = 0, res2 = 0;

	for (int i = 0; i < n; i++) {
		XOR ^= arr[i];
	}
	int sn = XOR & ~(XOR - 1);

	for (int i = 0; i < n; i++) {
		if ((arr[i] & sn) != 0) {
			res1 ^= arr[i];
		} else {
			res2 ^= arr[i];
		}
	}

	cout << res1 << " " << res2;

	return 0;
}

//Time complexity -> theta(n)

//INPUT
// 3 4 3 4 8 4 4 32 7 7

//OUTPUT
//8 32
