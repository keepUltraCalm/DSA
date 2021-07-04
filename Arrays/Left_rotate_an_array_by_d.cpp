//Q. Left rotate an array by d

//Brute...
/*
We know how to left rotate an array by 1
so we can do it d times to get the sol
Time: Theta(n*d)
Space: O(1)
*/

//Better
/*
so create an extra array of size d
copy first d elements
shift dth index to n-1 index elements to starting
arr[i-1]=arr[i] do i-d instead
add the extra array elements at the back
loop i=0 to d
arr[n-d+i]=extra[i];
Time: Theta(d+n-d+d) = Theta(n+d) = Theta(n)
Space: Theta(d)
*/

//Optimal Sol

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

void rotate(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
//the reverse function

void left_rotate(int arr[], int n, int d) {
    rotate(arr, 0, d - 1);
  //reverse the first d
    rotate(arr, d, n - 1);
  //reverse remaining
    rotate(arr, 0, n - 1);
  //reverse complete array now
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

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;
    left_rotate(arr, n, d);

    for (auto x : arr) {
        cout << x << " ";
    }

    return 0;
}

//Complexity Time: O(n)
//Space O(1)

//O/P
//3 4 5 1 2 
