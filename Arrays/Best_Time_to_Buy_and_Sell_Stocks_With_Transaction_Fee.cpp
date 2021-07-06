//Leetcode...BEST TIME TO BUY AND SELL STOCK WITH TRANSAC FEES

/*
A bit different q than a usual stock buy sell
The q says..you can do infinite transactions but
every transac costs you some amount of fees!!!!

NOTE!!
fees is only deducted on selling the stock

Now,the explanation
suppose the array is like this:
10 15 17 20 16 18 22 20 22 20 23 25

now lets create a table

bsp -> old bought state profit
ssp -> old sold state profit

days   stock price      obsp                    ossp     fees=3
  1(0)       10      -10 (1 stock)          0(if you sell you get 0 today)
  2          15       max(-10, 0-15)
  3          17       offcourse you
  4          20       will choose -10
  5          16       (both give you 1 stock)
  6          18
  7          22
  8          20
  9          22
 10          20
 day index start from 0

 days   stock price   obsp                 ossp          fees=3
  1          10      -10 (1 stock)          0
  2          15      -10 (1 stock)   now,how to calculate ossp
  3          17                      if -10 stock is sold and today's
  4          20                      price i 15, so you get a profit of
  5          16                     -10 + 15 - fees(3) = 2
  6          18                      which is better than 0..so sell.
  7          22
  8          20
  9          22
 10          20

Observe the table
first keep your obsp and ossp as -arr[0] & 0

now we will calculate nbsp & nssp -> n means new
lets first look at bought state

either you can not sell it..the ist stock priced at 10..
or you sell it and buy the 15 prices stock

if you sell the stock..ossp becomes 0...net profit 0..and you have
-15 in your account...but you have 1 stock...earlier at -10 you
had 1 stock.. -10 was better so continue it.

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

    int arr[] = {1, 3, 2, 8, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int fees = 2;
    int obsp = -arr[0];
    int ossp = 0;
    for (int i = 1; i < n; i++) {
        int nbsp = 0;
        int nssp = 0;
        //for bought state
        //if you buy from your ossp and it obsp becomes less
        //then you will keep the earlier..else update
        if (ossp - arr[i] > obsp) {
            nbsp = ossp - arr[i];
        } else {
            nbsp = obsp;
        }
        //for sold state

        /*
        Ok,so now lets talk about the sold state
          if obsp + curr_indx_value - 3(fees) > 0(which is the max ossp
           till now)
           change the new ssp or nssp
           else keep the prev in nssp
        */

        if (obsp + arr[i] - fees > ossp) {
            nssp = obsp + arr[i] - fees;
        } else {
            nssp = ossp;
        }
        ossp = nssp;
        obsp = nbsp;
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
8

if only one element present..o/p is 0
*/



