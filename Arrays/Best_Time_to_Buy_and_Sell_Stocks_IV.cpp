//Leetcode...BEST TIME TO BUY AND SELL STOCK IV
/*
Another dp problem..this time we have the same problem
but with a twist..we can do atmost k transactions

so,how do we solve this...now we cannot use the 2 transac
way everywhere everytime..its just for 2

so this means we need a 2-d array..i.e.,its a classic dp-problem
1. create a 2-d array----dp[k+1][n+1]
   rows are till k...columns are till n
2. we know one thing...0 day is invalid
   & how can we earn profit when we have 0 transac available
   also we will earn 0 profit if we buy and sell on the same day
   now, these stuffs mean..
   these things are first converted to 0 in dp array
3. Now, lets say we want 6th day 3 stocks ans??
   how will you find that..
   possibilities are...5th day 3 stocks would give you maximum
                       OR
                       5th day 2 stocks and buying one now would
                       give you maximum
   now,you might say but also check for 4 day 2 stocks
   ans:
   its already checked when you checked for 5 day 3 stocks
   for 5 day 3 stocks..you checked 4 day 3  &  4 day 2
   dp[i][j] stored the maximum of these two
   so you will get dp[k][n] as your ans                        
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

    int arr[] = {3, 2, 6, 5, 0, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    int dp[k + 1][n + 1];
    for (int i = 0; i < k + 1; i++) {
        dp[i][0] = 0;
        //0 day is invalid
        dp[i][1] = 0;
        //on day 1..you have 1 to k stocks..but your profit is 0
        //because you sold it this day only
    }
    for (int j = 0; j < n + 1; j++)
        dp[0][j] = 0;
    //you can have 0 profit with 0 transacs

    for (int i = 1; i < k + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + arr[j - 1] - arr[j - 2]);
            //just look above..for explanation
        }
    }
    cout << dp[k][n];
    return 0;
}


//Time : O(n*k)
//Space: O(n*k)

/*
O/P
7

if only one element present..o/p is 0
*/
