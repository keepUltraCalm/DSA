//Leetcode...BEST TIME TO BUY AND SELL STOCK II

/*
It is follow up of buy and sell stock I
In this problem...we are given infinite transactions in hand..
1 Transaction means buy and sell
Only constraint is we need to buy sell buy sell
we cannot buy buy
We need to maximize our profit

Now this problem is easier than the first problem
because of the fact that we atre given infinite transac
what i mean?
suppose we have 1 4 5 7
if i could do only 1 transaction then i need to find min and max
i.e., 7-1=6
but since i can do as many as i want now, can i do (4-1)+(5-4)+(7-5)
i.e., i don't need to maintain any min & max_profit
it will always be equla to the cummulative sum

so, when we find a local minimum(adjacent left value is greater)
buy the stock...and when a greater value then curr comes sell it
add all possibles like this to get the ans
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

    int arr[] = {5, 2, 6, 1, 4, 7, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int profit = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            profit += arr[i] - arr[i - 1];
        }
    }
    cout << profit;
    return 0;
}


//Time : O(n) 1 traversal needed
//Space: O(1)

/*
O/P
13
*/
