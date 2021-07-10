
/*
Leetcode : NEXT PERMUTATION
You are given an array..find out the exact next
permutation after it

for example: 3 2 1
ans is 1 2 3

Brute fore:
You will find out all the permutations of the array
linearly iterate and match given with these
then find the next of the given permutation
O(n! + n) n! to generate, O(n) to find
O(n) to store

Optimal Sol:
Lets take another example
 1 3 5 4 2
 now, just tell me one thing..a very simple observation
 can you make anything greater than 5 4 2 from the last 3
 ofcourse no..as they are descending order
 so to create the next after this...i need to change this 3
 to the just greater than itself element..on its right
 now, see that we have 4 which is the smallest element which is
 greater than 3 on its right
 ((this is impt) because left is already on its correct position)
 So, now swap these numbers
 so you get 1 4 5 3 2
 but is it the next...no
 how to make the smallest number..buy sorting the right part
 now, we can do that here by reversing the right also..why?

because 5 4 2...this was descending order right..reverse gives you sorted

but you will say..what is the guarantee that the number you swapped was
greater than the last i.e, 3<5 & 3>2
now observe..we stopped when found a number less than 5..i.e, 4
this proves 1st part of inequalty
for 2nd part..you found the smallest element greater than 3..
so it is greater than 2 also
so final ans is
 1 4 2 3 5
 I hope you understood it now😃
 You will not find a better expanation anywhere😎
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mod 1000000007;

void reverse(int arr[], int l, int h) {
    while (l < h) {
        swap(arr[l], arr[h]);
        l++;
        h--;
    }
}

void sol(int arr[], int n) {
    int i = n - 1;
    while (i >= 1) {
        if (arr[i - 1] < arr[i])
            break;
        i--;
    }
    if (i == 0) {
        reverse(arr, 0, n - 1);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        return;
    } else {
        int j = n - 1;
        while (j >= i) {
            if (arr[j] > arr[i - 1]) {
                swap(arr[j], arr[i - 1]);
                // for (int i = 0; i < n; i++)
                //     cout << arr[i] << " ";
                // cout << '\n';
                reverse(arr, i, n - 1);

                for (int i = 0; i < n; i++)
                    cout << arr[i] << " ";
                return;
            }
            j--;
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

    int arr[] = {1, 3, 5, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    sol(arr, n);

    return 0;
}

/*
O/P

1 4 2 3 5


Time:  O(n)to find smaller + O(n) to find the (just greater number)
 + O(n) worst case in reversing
 so,
 Time: O(n)
Space: O(1) in place..same array is modified
*/
