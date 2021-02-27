//Q..
//To check whether a string is palindrome using recursion


#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

//so what is this function doing??
//first of all..what is our requirement...
//we want to check first and last char of the string..
//if it matches..we proceed...else we directly return false..
//as string is not palindrome....

//now, if the string given is palindrome!!!
//there are two possibilites..length is odd or even
//now if length is odd....n1 == n2
//if even..n1 will become > n2..
//once we reach any of these two..we can surely say that
//our string is palindrome

//and we check recursively till n1 < n2
//now in the input..length of string is odd which is 7
//so both n1 and n2 collide at char c..so we print yes

bool check(string s, int n1, int n2) {
	if (n1 >= n2) {
		return true;
	}
	if (s[n1] == s[n2] && n1 < n2) {
		return check(s, n1 + 1, n2 - 1);
	} else {
		return false;
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


	string s = "abacaba";
	int n1 = 0;
	int n2 = s.length() - 1;
	bool ans = check(s, n1, n2);

	if (ans) {
		cout << "Yes";
	} else {
		cout << "No";
	}


	return 0;
}



//INPUT

//abacaba

//OUTPUT

//Yes


//Time complexity

// O(n)

//Space

//O(n)..because of function call stack
