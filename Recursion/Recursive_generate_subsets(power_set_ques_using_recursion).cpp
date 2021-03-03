//Q..

//Generate subsets or subsequences of given string
//now it is a set..so we have unique elements

//OK..so we have already done this ques before using bits..the power set ques
//Now, we know what a subset is..a continuous part substring from parent
//But what is subsequence??
//A subsequence is achieved by removing characters from subset while
//maintaining the original order.

//Now.let's take an example!!
//suppose we are given a string ABC
//we need to print "", A, B, C, AB, BC, AC, ABC

//note here that AC is a subsequence

//ok,now let's understanding how is recursion working here

//we have got two choices..either we will take the character or we don't take it

//observe the tree
//on left..we don't take
//on right..we take

//we have 2^n subsequences..

/*                    "" -->empty
                  /              \
                 ""               A
                /   \            /  \
               ""     B         A    AB     (observe..every time on left i ignore the element
             /   \   /  \     /  \   /  \          and on right...i take it)
            ""   C   B  BC    A  AC  AB  ABC

            see,we have 2x2x2 i.e., 2^3..i.e., 2^n choices


            ok, now how will we solve this problem

     Now, if you follow me..recursion will be super easy!!😍

     what is the first step...understand the pattern..draw a tree
     now,what's the next step...
     how are you going to call the various function calls
     and final step...we need to think when are we going to stop..what's the base case!!


 */

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

//so what's this function doing..
/*first we are passing default parameters as c++ supports this

first ..the recursive calls
so we are taking an empty string curr and an int i=0

now, in every function call we increment i, but
in one call we add char..and in other..we ignore it

Talking about base case now:

Now here comes the use of i passed in argument of function

This i will tell us when we reach length of string
as it keeps track of the index of string....int this case when we reach
3rd layer of tree..not including the root..we print subsequence

and then we return(when we reach base case we want to return..not break)...
as now the previous call continues its second function
*/

void generate_subsets(string &s, int i = 0, string curr = "") {
//default parameters in c++
	//base case
	if (i == s.length()) {
		for (auto x : curr)
			cout << x;
		//printing subsequence
		cout << "\n";
		return;
	}
	//the two recursive calls
	generate_subsets(s, i + 1, curr);
	generate_subsets(s, i + 1, curr + s[i]);
	//this one adds the char
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

	string s = "ABC";
	generate_subsets(s);

	return 0;
}


//INPUT

//ABC

//OUTPUT

//
//C
//B
//BC
//A
//AC
//AB
//ABC


//Time complexity
//O(2^n)..why 2..because we got 2 choices
//n-> length of string

//Space complexity

//theta(Height of tree)
//that's the maximum number of calls in function call stack


