/*
Q. Leetcode : Majority Element I

Find the element which appears more than floor(n/2) times in array
now, because of n/2 given..we can definitely say only 1 majority element exist
and it is given in Q that it definitely exists

Brute:
O(n^2) time
Space O(1)
take an element..count its number of occurences
if >floor(n/2)..this is the ans
else move ahead

O(nlogn+n)
O(1)
2nd approach
Sort the array
maintain a max var
if this max becomes >n/2..this was the element

Better
Use a hashmap
If there are no collisions hashmap find is O(1)
Now, iterate through array..increase frequency if already present
else
add that element
myMap(arr[i])++ ,check this..
whenever frequency becomes >floor(n/2) you got the ans
Time: O(n)
Space : O(n)
*/

/*
Optimal sol:

Moore's voting algorithm

See...we are 100% sure majority element is present
so even on using all the other numbers to exhaust this element
it will still be left
1 1 1  3 4   1 will still be left
This is the intution..
if it occurs between two different..then it will occur later again
if it occurs together..imagine..then count will never become 0
if it is mixture of both..we will see it again

if in Q it is given majority element might not exist...then you 
need to run the final loop to check if the element you found
was actually occuring > n/2 times

suppose your array is like x1 x2 x2 x1 x3......and so on right side
So x1 x2    this shows that if your elements are divided
   x2 x1    in pairs and every pair elements are distinct
   x3 x1    then you cannot have any element n/2 times..
            which means ans is available on the right side
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

    int arr[] = {7, 7, 5, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count = 1;
    int ans = arr[0];
    for (int i = 1; i < n; i++) {
        if (count == 0)
            ans = arr[i];
        if (arr[i] == ans)
            count++;
        else
            count--;

    }
    cout << ans;

    return 0;
}

/*
O/P
5

Time: O(n)
Space: O(1)
*/
