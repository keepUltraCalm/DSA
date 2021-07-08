/*
Leetcode : SUBARRAYS SUM = K

Brute:
O(n^2) check for all
approach:
Generate all the subarrays
maintain a counter variable
if you find subarray with sum k
count++

OPTIMAL Sol:
Now, to understand this approach,
you need to take a look at maximum subarray with 0 sum concept,
I explained earlier
now the logic is
sum maintains the prefix sum as usual
if sum==k replace by 0
you count++..because you found 1 ans
and always add that sum to map with its occurence number
now, if sum!=k
check is the sum-k diff available in map
if yes..how many times..count+=that many times
now if sum-k is not available in map
so you just as always add the sum in map paired with its occurence
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

    int arr[] = {3, 4, 7, 2, -3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> myMap;
    // myMap.insert({5, 0});
    // myMap[5]++;
    // cout << myMap[5];
    int k = 7;
    int sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k) {
            count++;
        }
        if (myMap.find(sum - k) != myMap.end()) {
            count += myMap[sum - k];
            //[sum-k] key's value is added
        } else {
            ++myMap[sum];
            //if it was not present..it will create one with occurence 1
            //if present..it will increment occurence
        }
    }
    cout << count;
    return 0;
}

/*O/P
4
*/


//Time : O(n)
//Space : O(n)


