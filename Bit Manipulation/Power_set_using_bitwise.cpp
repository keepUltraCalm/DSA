//Q.. 
//To print power set of a set using bits manipulation

//A very rare topic in interviews...
//But if someone asks a ques on bits..this is a must know

//okay..so what we need to do..lets first understand that..
//we are given a string...and we need to print its power set
//i.e., all the distinct possible combinations..bc and cb should not repeat..that's the rule
//of power set
//for ex..if we have string length as 2..for example..ab is a string
//so we will have different combinations of 0,1,2 length strings..

//in the above example it will be
// 0...empty
// 1   a , b
//2    ab

//now how can we do it using bitwise...
//the logic is simple..
//we know that we are having two choices...either we will take the character
//of the string or leave it...

//and every time the choice combo should be unique...for example 1 0 0 and 0 1 1 are different

//so i can say that we will have (2^n)-1 possible combinations available + 1 for empty..where
//n is the length of the string given to us....7 + 1(empty)

//now,how can we integrate this stuff with bits??
//yes...just observe...what we have got from 0 to (2^n)-1 numbers..
//all of these have unique combo choice...

//now, why it works??
//observe..if we take ab
// which means we take
//0  1  1
//c  b  a
//..i am going right to left(it will be checked in this order)
//now ba will automatically cut off..beacuse the number will remain the same..
//i.e., 0 1 1....which is 3 here
//in this way i will get my ans

//now how will i check whether the bit is set or not..so that i will be able
//to implement the above logic

//lets say when i reach 6...which is 1 1 0....i.e., counter becomes 6
//so i will print bc...
//now to check for set bit we use the following

// 6 & (1<<0)..to check whether first bit is set
//working.. 6 is  1 1 0
// 1<<0..         0 0 1
//and is equal to 0..so ist bit of 6 is not set..
//so don't print a
//similary check for 2nd bit..keeping i=1
//and so on

//now why starting from 0..
//because for the first bit..i don't want to change 1
//only then i can check that 1st bit is set or not


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


	string s = "abc";
	int n = s.length();
	int x = pow(2, n);
	//gives me 2^n

	for (int counter = 0; counter < x; counter++) {
		for (int i = 0; i < n; i++) {
			if ((int)(counter & (1 << i)) != 0)
				//explained the logic above
				//now why i have explicitly mentioned int??
				//because if gives me a bool..i want an integer
				//the right side 0 is not a bool 0..it is an int 0
				//don't get confused
				//it makes everyhing clear
				cout << s[i];
		}
		cout << "\n";
	}


	return 0;
}



//INPUT

//abc

//OUTPUT

//
// a
// b
// ab
// c
// ac
// bc
// abc


//Time complexity

//theta(nx)...where n is the length of string
//x = 2^n
