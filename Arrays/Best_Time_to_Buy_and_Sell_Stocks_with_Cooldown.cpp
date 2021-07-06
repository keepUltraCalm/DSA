//Leetcode...BEST TIME TO BUY AND SELL STOCK WITH COOLDOWN
/*
In this problem we are given a cooldown period of 1 day
which means if we sell our stock, then we need to
wait one day to buy other stock
What will be the max profit then?

Its similar like the transac cost problem discussed earlier
The diff here is we need to maintain an ocsp
ocsp-> old cooldown state profit

It will use the above one above itself(one day before is given in Q)
value of ossp
Now, instead of clculating obsp by using ossp, we use ocsp
thats the logic!!!!
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

    int arr[] = {1, 2, 3, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int obsp = -arr[0];
    int ossp = 0;
    int ocsp = 0;
    //this is 0 because no cooldown when we don't sell
    //introducing a new variable(a table column)
    for (int i = 1; i < n; i++) {
        int nbsp = 0;
        int nssp = 0;
        int ncsp = 0;

        //for bought state
        if (ocsp - arr[i] > obsp) {
            nbsp = ocsp - arr[i];
        } else {
            nbsp = obsp;
        }
        //if cooldown value - arr[i] > previous bought state value
        //change new 
        //else
        //keep the previous value

        //for sold state
        if (obsp + arr[i] > ossp) {
            nssp = obsp + arr[i];
        } else {
            nssp = ossp;
        }
        //everything of this state is same as prev q
        //because cooldown is not linked to sell, its only linked to buy
        //only diff is there is no fees

        //for cooldown state
        //as its for one day
        //compare it with its above row ossp value
        //change ncsp if greater
        //else ncsp is still previous value
        if (ossp > ocsp) {
            ncsp = ossp;
        } else {
            ncsp = ocsp;
        }
        ossp = nssp;
        obsp = nbsp;
        ocsp = ncsp;
        //update old after every iteration..
        //new variables are just for comparisons.
    }
    cout << ossp;
    return 0;
}


//Time : O(n)
//Space: O(1)

/*
O/P
3

if only one element present..o/p is 0
*/
