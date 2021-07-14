//ARRAY
/*
Q. MINIMUM OPERATIONS REQUIRED TO MAKE ARRAY PALINDROME


Given an array of positive integers. We need to make the given array a
 ‘Palindrome’. The only allowed operation is”merging”
 (of two adjacent elements). Merging two adjacent elements means replacing
  them with their sum. The task is to find the minimum number of merge
  operations required to make the given array a ‘Palindrome’.
To make any array a palindrome, we can simply apply merge operation n-1 times
 where n is the size of the array (because a single-element array is always
 palindromic, similar to single-character string). In that case, the size of
 array will be reduced to 1. But in this problem, we are asked to do it in the
 inimum number of operations.

lets take 1 4 2 3 5
 brute force
 ...check for every element..then calculate
 for sum possible on its right..like for 1 check for 1   4 2 3 5
 and 1  (adding)6 3 5 then for 1  9 5..and son on...
 Time cubic O(n^3) atleast

 Optimal sol:
 Use 2-Pointers approach
 1. i=0, j=n-1
 now, if both are equal..so palindrome property is satisfied..so i++, j--
 if left part is smaller..make an operation..++count..and i++
 (we need to check will this give us palindrome)
 of for i..because if i do this on j..it was already big..
 becomes more big..so diff increase more
 else
 same for j
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

int sol(int arr[], int n) {
    int i = 0, j = n - 1;
    int count = 0;
    while (i < j) {
        //i==j will only occur in case of odd size
        //first if will be satisfied..which does nothing
        //so no need to write
        if (arr[i] == arr[j]) {
            i++;
            j--;
            //both change
        } else if (arr[i] < arr[j]) {
            i++;
            arr[i] += arr[i - 1];
            //as arr[i] is smaller
            count++;
        } else {
            j--;
            arr[j] += arr[j + 1];
            //as arr[j] is smaller
            count++;

        }
    }
    return count;
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

    int arr[] = {1, 2, 3, 5, 10, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = sol(arr, n);
    cout << ans;

    return 0;
}

/*
O/P
2

Time: O(n)
Space: O(1)
*/
