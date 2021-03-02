//Q..
//Cut the rope to get the maximum pieces...
//such that the length of pieces should be either a,b or c
//given 0 <a,b,c <=n

//ok..so how should we approach this problem
//lets understand..
//from the three posible choices..we will either take
//a or b or c..any one...every time
//and then which among these three paths is giving us our maximum value
//following this pattern..we will get a tree

/*as

  n=23, a=12, b=9, c=11


  // n-a on left, n-b in middle, n-c on right

               23
         /     |     \
        11     14     12
     /  |  \  / | \   / | \
    -ve 2  0  2 5  3  0 3  1

     Now,just observe...all the values are <a,b,c
     so,they are going to give me negative...
     which means we cannot get any answer....beyond this layer

     and everytime we add 1 to that recursive function call..
     but we don't add 1 when we get -ve...which returns -1..
     this is why we check res == -1

     what i mean to say is..suppose we are not getting any ans
     i.e., all values of tree(leave root) are giving negative..then we
     know that we didn't get any valid options to cut..i.e., cuts are not possible..
     now if i don't check if else condition for res == -1
     we will get -1 + 1 = 0..which is the wrong ans 

     now,talking about the base cases..
     when we get -ve..we return -1..as discussed above
     when we get 0..we return 0
     but the final returned value after doing below if else will be
     1+ 0...as we made 1 cut

*/


#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int ans(int n, int a, int b, int c) {
	if (n == 0)
		return 0;
	if (n < 0)
		return -1;
	//these two are the base cases
	int res = max(
	              max(
	                  ans(n - a, a, b, c),
	                  ans(n - b, a, b, c)
	              ),
	              ans(n - c, a, b, c)
	          );
	//we cannot use stl max for 3..only 2
	//so doing it this way
	if (res == -1)
		return -1;
	else
		return 1 + res;
	//this will give us our final returned value
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


	int n = 23;
	int a = 11, b = 9, c = 12;
	int x = ans(n, a, b, c);
	cout << x;

	return 0;
}



//INPUT

//23 -> n
// 11 9 12 -> a b c

//OUTPUT

//2(just have a look at the tree)


//Time complexity

// O(3^n)..in this case
//first of all we can find only upper bound
//now how can we get that??

//ans:
//what can be the minimum values of a b c
//1....now suppose all 3 are 1
//how many levels will we have..n
//power it with 3..as we have 3 choices

//Space

//first any one of the 3 calls will complete
//then second..then third
//so space required is height of tree..as atmost we will have that
//number of calls in the function call stack

//we will talk about how can we optimize it using
//dynamic programming later in the dp part
//because just observe..we have some numbers repeating in tree
//will talk about it later😉
