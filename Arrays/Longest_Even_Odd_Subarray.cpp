//ARRAY
/*
Q. LONGEST EVEN ODD SUBARRAY
Find the maximum contiguous array of form even odd even odd
can start with odd also
return the max length

Brute:
O(n^2) take all subarrays  [i to j]
check i's right how many odd even length you get..when you moved j
update max acc to curr>max

Optimal:
Something like Kadane's Algo
O(n) time
O(1) space
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

    int arr[] = {10, 12, 14, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    //let me explain what are we doing
    bool isEven;
    //this will check is num odd or even
    int curr_count = 1;
    int max_count = 1;
    //I have taken the first element regardless even or odd
    //combination will be taken care later

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] % 2 == 0)
            isEven = true;
        else
            isEven = false;
        //first set your bool
        if (arr[i] % 2 == 0 && isEven == true) {
            curr_count = 1;
        } else if (arr[i] % 2 != 0 && isEven == false) {
            curr_count = 1;
            //either both should be odd or even
            //so we start again
        } else {
            ++curr_count;
            //we found odd-even
        }
        //if max got changed update
        max_count = max(curr_count, max_count);
    }

    cout << max_count;
    return 0;
}

/*
O/P
3

Time : O(n)
Space : O(1)
*/
