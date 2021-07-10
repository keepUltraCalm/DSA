/*
Q MAXIMUM SUM SUBARRAY
Kadane's Algorithm

Brute:
Generate all subarrays...maintain curr array sum and max sum variables
update max if you get greater curr sum

A O(n^3) sol will be instead of adding the value to sum directly..
you run a loop from i to j to calculate sum...
useless loop

Time : O(n^2)
Space : O(1)

Optimal Solution below!!!!
The idea is..you have two choices..either extend previous
or start new
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

    int arr[] = { -5, 4, 6, -3, 4, -1};
  //see when you add -3 to currSum, it can be increase later when you add 4(next)
  //that's why when currSum<0 only, we do currSum=0
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = INT_MIN, currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        //we increase currSum till it can..until it doesn't becomes < 0
        /*
        if it becomes 0..we have already stored the
        maximum it gave us in maxSum before becoming -ve
        */
        if (currSum < 0) {
            currSum = 0;
        }
        if (currSum > maxSum)
            maxSum = currSum;
        //it will also cover -ve's as it will update
        //that too..if i get -2 as currSum
        //note i have taken maxSum = INT_MIN..for a reason!!!!
        //and -5 was my maxSum..it will update it😉

    }
    cout << maxSum;

    return 0;
}

/*
O/P

11

Time : O(n)
Space : O(1)
*/
