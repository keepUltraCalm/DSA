
//Q. COUNT SUBARRAYS PRODUCT LESS THAN K

/*
Brute force:
Check all O(N^2)
*/

//Conditions:
// k is +ve
//array elements are +ve
//No integer overflow while multiply..given

//Optimal sol
/*
We will use sliding-window technique
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

    int arr[] = {10, 5, 2, 6};
    int k = 100;
    int n = sizeof(arr) / sizeof(arr[0]);
    if (k == 1 || k == 0) {
        //ans will be 0..
        cout << 0;
    } else {
        int left = 0, right = 0, prod = 1, count = 0;
        while (right < n) {
            prod *= arr[right];
            while (prod >= k)
                prod /= arr[left++];
            count += 1 + (right - left);
//what this line calculates?
/*
Let's take an example
2 5 8...lets say we are on 5(right)...and left is 2
it gives me the value how many subarrays I can make [left to right]included
(not including subarray [2],because i'm on 5) which is less than k
1 +(5's index - 2's index) = 1 +(1-0) = 2...which is 5, 5 8
*/
            right++;
        }
/*
Logic is simple...
when product becomes greater than k..we run a while loop till
we don't find subarray with product less than k
and we also increment the left
*/
        cout << count;
    }

    return 0;
}

/*
O/P
8

Time :  O(n)
Space : O(1)

*/



