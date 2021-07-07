//Find the MAXIMUM PRODUCT SUBARRAY

//Brute
//Generate all subarrays, calculate max product
//O(n^2)time     O(1)space

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

    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxx = arr[0];
    int max_here = arr[0];
    int min_here = arr[0];
    for (int i = 1; i < n; i++) {
        int temp = max_here;
        max_here = max({arr[i], arr[i]*max_here, arr[i]*min_here});
        //the two after arr[i] are the cases if arr[i] is +ve,
        //arr[i] is -ve respectively
        //min_here gives -ve's biggest..so its *arr[i](-ve) gives maximum
        //max_here gives +ve's biggest..so its *arr[i](+ve) gives maximum
        min_here = min({arr[i], arr[i]*temp, arr[i]*min_here});
        //this min_here calculation is required for above calculation of max_here
        //temp variable is necessary as max above line max_here = changes its value
        //so we store ot earlier in temp
        //arr[i] comparison is necessary..if min_here and max_here
        //both are +ve..and arr[i] is -ve, so min_here should be updated to -ve

        maxx = max(max_here, maxx);
    }
    cout << maxx;

    return 0;
}

//O/P
/*
6

 I/P   2, 3, -2, 4, -1, -3, 4
O/P    48
Time : O(n)
Space : O(1)

*/
