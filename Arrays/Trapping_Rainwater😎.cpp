//Q. TRAPPING RAINWATER

//Interesting because i will be discussing a rare two-pointer approach!!!

//Brute force approach
/*
First, you need to observe that no water can be stored on extremes
so run a loop from i=1 to n-2
for that particular index...find max on its left, find max on its right
find min of these two
add (value_received - arr[i]) to result
for all i's
Time : O(n^2)..one for all array traversal..(another for i)
Space : O(1)

*/

/*Can we do better??
Create two arrays..right and left
Right[i] stores the maximum value i can have on right
same goes for left[i]
now,while traversing the array...find min(left[i],right[i])=mini
ans+=mini-arr[i]
Time : O(n) ..3 traversals
Space : O(2*n)
*/

//Optimal Sol
/*
The optimal solution uses a two pointers approach
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

    int arr[] = {4, 2, 0, 6, 2, 7, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    //first initialize these two as extremes
    int max_left = arr[0];
    int max_right = arr[n - 1];
    int res = 0;
    int left = 1, right = n - 2;
    //these are the iterators which we will move -> 2nd from first and last
    while (left <= right) {
        //now why =  because when we are at left=right we need to check for
        //that particular tower..max_right is not equal to right always..
        //same for left
        if (max_left < max_right) {
            if (arr[left] <= max_left)
                res += max_left - arr[left];
            else
                max_left = arr[left];
            left++;
            //use max_left for diff calculation with arr[i] if max_right
            //is greater
            //if arr[i] is >
            //then update max_left, left++ and then again compare
            //with max_right


        } else {
            if (arr[right] <= max_right)
                res += max_right - arr[right];
            else
                max_right = arr[right];
            right--;
        }
    }
    cout << res;

    return 0;
}

/*
O/P
10

Time :  O(n) 1 traversal
Space : O(1)

*/
