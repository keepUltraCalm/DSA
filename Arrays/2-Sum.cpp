//Q   FIND DUPLETS
//Leetcode :2 sum problem
/*
Constraints:
One element is not used twice
Exactly 1 solution available
return ans in any order
you need to return the index of the duplets

Brute force:
O(n^2)
find all the duplets...
i set..travese all j>i
i++
then again
calculate sum
when found: return indexes

Optimal sol:
Maintain a map of arr[i],its index
if target - arr[i] is not present 
add to map
else
you got the ans
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

    int arr[] = {2, 6, 5, 8, 11};
    int tar = 14;
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int>myMap;
    for (int i = 0; i < n; i++) {
        if (myMap.find(tar - arr[i]) != myMap.end()) {
            cout << myMap[tar - arr[i]] << " " << i;
            //can also use vector for returning from function
            break;
        } else {
            //myMap.insert({arr[i], i});
            myMap[arr[i]] = i;
        }
    }
    return 0;
}


/*
O/P
1 3

Time Complexity: O(n)
Space Complexity: O(n)
*/

