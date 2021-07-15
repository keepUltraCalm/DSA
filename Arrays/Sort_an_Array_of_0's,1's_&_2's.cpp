//ARRAY
//SORT AN ARRAY OF 0's, 1's and 2's

/*
Brute:
Sort the array
Time : O(logn)
Space : O(1)

Better:
Use Counting Sort
what we do is..create 3 variables..store counts of 0's, 1's and 2's
now after 1st iteration..we have all 3 final counts
so add them in array one by one..first run from i=0 to <count1
then count1 to <count1+count2 then the last


int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1)++count1;
        else if (arr[i] == 2)++count2;
        else
            ++count0;
    }
    //cout << count0 << " " << count1 << " " << count2 << '\n';
    for (int i = 1; i <= count0; i++)
        cout << "0" << " ";
    for (int i = count0 + 1; i <= count0 + count1; i++)
        cout << "1" << " ";
    for (int i = count0 + count1 + 1; i <= count0 + count1 + count2; i++)
        cout << "2" << " ";
    cout << '\n';


Time : O(n) 2 traversals
Space : O(1)


Optimal:
DUTCH NATIONAL FLAG ALGORITHM

Explanation below
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

    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    /*
    see what we want to do is maintain the values:
    everything on left of low is 0
    everything on right of high is 2
    and we run loop till mid<=high
    */

    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high) {
        //if you don't include = what will happen??
        //0 0 0 0 1 1 1 1 1 0 2 2
        //m h
        //you missed the last
        switch (arr[mid]) {
        case 0:
            swap(arr[low], arr[mid]);
            low++;
            mid++;
            break;     //switch case syntax

        case 1:
            mid++;
            break;

        case 2:
            swap(arr[mid], arr[high]);
            high--;
            break;
            //there is no default case
        }
    }
    for (auto x : arr)
        cout << x << " ";
    //enhanced for loop doesn't work inside function(if i create one)

    return 0;
}

/*
O/P

0 0 0 0 0 1 1 1 1 1 2 2

Time: O(n) 1 traversal
Space: O(1)
*/
