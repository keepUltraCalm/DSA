/*
Longest subarray with given sum


<-------------------------->
           sum
____________________________
|  |  |  |  |  |  |  |  |  |
i           j   **          **
<----------->       ??can i say this sum is k
     sum-k


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

    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    int sum = 0;
    int maxi = 0;
    unordered_map<int, int> myMap;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == k)
            maxi = i + 1;
        if (myMap.find(sum - k) != myMap.end()) {
            maxi = max(maxi, i - myMap[sum - k]);
        } else {
            myMap.insert({sum, i});
        }
    }
    cout << maxi;

    return 0;
}

/*
O/P
4

-6 6 2 2

Time : Theta(n)
Space : O(n)
*/
