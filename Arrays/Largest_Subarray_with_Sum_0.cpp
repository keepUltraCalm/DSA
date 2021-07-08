/*
Leetcode : LARGEST SUBARRAY WITH SUM 0

Brute:
O(n^2) check for all
approach:
Generate all the subarrays
maintain a max length variable
when you find a subarray with length 0
check is its length greater than max length..
if yes update

OPTIMAL Sol:
Now, to understand this approach,

s= sum from starting index 0 to i
s is also sum of entire array(just taking this example)
now ind j till n-1(n is size) will give you 0
that's the logic!!

<-------------------------->
           s
____________________________
|  |  |  |  |  |  |  |  |  |
i           j   **          **
<----------->       ??can i say this sum is 0
     s

     Now, we need to store the sum..or prefix sum
     we use map for that
     so what we do is..
     first, we maintain a maxi variable..for max length

     1, -1, 3, 2, -2, -8, 1, 7, 0, 2, 3...an example

     now add 1 to your sum
     check is sum ==0 if no
     add that prefix sum and index in map
     now move ahead
     is sum==0 now, yes! because
     1-1=0 so update maxi as 1+i = 2
     now again go ahead
     now sum=3...so go in else part
     but now there is also a check required that is this prefix sum
     in map...if yes..then what index...
     subtract the curr_index - this index
     you get a length..check is this length > maxi
     update maxi...this is how you get your answer
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

    int arr[] = {1, -1, 3, 2, -2, -8, 1, 7, 0, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, int> myMap;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            maxi = i + 1;
        } else {
            if (myMap.find(sum) != myMap.end()) {
                maxi = max(maxi, i - myMap[sum]);
            } else {
                myMap.insert({sum, i});
            }
        }
    }
    cout << maxi;
    return 0;
}

/*O/P
6
*/


//Time : O(n)..unordered_map find is O(1) on average..implemeted as hastable
//map in c++..ordered find in logn..implemeted as sb bst
//Space : O(n) worst case
// Although can be ignored ,its auxiliary space..because can be printed also
