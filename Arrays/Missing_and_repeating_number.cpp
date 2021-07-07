/*
MISSING AND REPEATING NUMBER

Q Given an array of size n
numbers in the array are from 1 to n both included
1 no. is missing..and 1 no. is repeated twice
Find the numbers

Brute force:
Sort the array
when adjacent diff is 0..repeating
when adj diff 2..repeating

Better:
Create a hashtable of size n+1
increment table[arr[i]], if it becomes two..repeating no.
leave 0 index
any other index which is 0 is missing no.

Optimal:
calculate sum=s (1 to n) n*(n+1)/2
calculate s^2 = n*(n+1)(2*n +1)/6
s-(all array sum) = any value
this will actually be X - Y = any value..4
X is missing no. Y is repeating no.
Similarly, s^2 - (all arr elements squares sums) = any num..lets say 24
So we will have X^2 - Y^2 =24
Can you solve the two equations.... yes!!
and you can calculate x and y
if integers overflow occurs..use long long int
X gives missing..y gives repeating
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int main() {

    cout << fixed;
    cout << setprecision(2);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[] = {1, 3, 4, 2, 5, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int S = n * (n + 1) / 2;
    int S2 = n * (n + 1) * ((2 * n) + 1) / 6;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum1 += arr[i];
        sum2 += arr[i] * arr[i];
    }
    int xy_sub = S - sum1;
    int x2y2_sub = S2 - sum2;
    int xy_add = x2y2_sub / xy_sub;
    int x = (xy_add + xy_sub) / 2;
    int y = x - (xy_sub);
    cout << x << " " << y;

    return 0;
}

//O/P
//6 5

//Time : O(n) 1 traversal😎 
//Space : O(1)



