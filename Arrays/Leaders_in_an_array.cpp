//Q. Leaders in an array problem?
/*
We are given an array...we need to print all the elements
whose right elements are less than its value(strictly).

Brute sol
Traverse the array elements,
Run another loop to check if curr elements right are less or not!
Time : O(n^2)
Space : O(1)
*/

//Optimal Sol
//We will print the numbers from right to left
//because acc to q, we ned to check the right of each elements,
//so maintaining the max from right is easy

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

void leaders(int arr[], int n) {
    int max = arr[n - 1];
    cout << arr[n - 1] << " ";
    //last element is off course leader
    for (int i = n - 2; i >= 0; i--) {
        //now just maintain the max element on the right
        //and check if curr element is greater??
        //if greater print it
        if (arr[i] > max) {
            cout << arr[i] << " ";
            max = arr[i];
        }
    }
}

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

    int arr[] = {7, 10, 4, 10, 6, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    leaders(arr, n);

    // for (auto x : arr)
    //     cout << x << " ";

    return 0;
}

//Complexity Time: Theta(n)
//Space O(1)
//Theta(n) if we need to print the correct order
//put result elements in stack.

//O/P
//2 5 6 10
