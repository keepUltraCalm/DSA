/*
Q. Leetcode : Majority Element II

Find the element which appears more than floor(n/3) times..
but it is not guaranteed that you may find always...
but you can find atmost 2

All previous approaches are same as Majority Element I

Optimal sol:

Boyer Moore voting algorithm

Only 2 elements can be present more than n/3 times..
because they both have more than n/3 occurences in array individually

which means only these two elements will cancel each other
that's why we go for making their seperate variables with counts
like we were maintaining variable(see the logic in previous q)
for one majority element
note in this q you can have 2 majority elements..or 1 or no ans
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

    int arr[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int num1 = -1;
    int num2 = -1;
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == num1)
            ++count1;
        else if (arr[i] == num2)
            ++count2;
        else if (count1 == 0) {
            num1 = arr[i];
            count1 = 1;         //code is pretty self explanatory
        }
        else if (count2 == 0) {
            num2 = arr[i];
            count2 = 1;
        }
        else {
            count1--;
            count2--;
        }
    }
    /*now we got the 2 numbers..but we need to check
    because we only knew atmost 2 can exist..but 0 can exist as well
    */
    int x1 = 0, x2 = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == num1)++x1;
        if (arr[i] == num2)++x2;
        //counting occurences..verifiying
    }
    if (x1 > floor(n / 3))//check was it > n/3
        cout << num1 << " ";
    if (x2 > floor(n / 3))
        cout << num2 << " ";
    cout << '\n';
    return 0;
}

/*
O/P
1 2

Time: O(n) + O(n) for verifying
Space: O(1)

If the q is for n/k brute, sorting and hashmap approaches are the ways😁
*/
