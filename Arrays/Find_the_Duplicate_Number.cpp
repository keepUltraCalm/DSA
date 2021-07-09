//Q Find DUPLICATE IN AN ARRAY OF N+1 INTEGERS

/*
Constraint: [1,n] elements range
length of arr = n+1 
*/

/*
O(n^2) brute force check on right of curr element

Sorting O(nlogn)

Use hashtable O(n) time O(n) space
create a hastable of arr size + 1 

Change the array to -ve..
you are on curr element..now take the mod of
that value(as it might get changed to -ve), though all elements
given are +ve by default)
and go to this index and change the value to -ve
once you find that this value is already -ve..you get your ans
don't use as it modifies array

4th approach...FLYOD CYCLE DETECTION
Now,lets understand this approach
since there is a repeating element, there is always a cycle
Now, assume
2 5 9 6 9 3 8 9 7 1
how will be cycle look
    2 -> 9 -> 1 ->5 -> 3 ->6 ->8 -> 7
this 9   <---------------------------|

Now,what i can say is..when the slow & fast will meet..what we can say is
fast pointer must have travelled an extra distance of a
now a is the distance travelled by slow(2a is travelled by fast)

             _y
-> -> ->  @/   \@@
   x       \ _ /
             z
          assume a cycle this way
          @ is the ans point
          @@ is the point where your slow fast collide
          x is the length of non-cycle part(left of cycle)
          now, z is length from @@ to @
          y is length from start to @@ i.e, a

          we can prove that z=x lets see😲

          length of fast = 2* length of slow = 2a or x + k*L + y
          C is the constant no. of times fast completed cycle
          slow doesn't complete cycle because fast crosses it..run some examples to see
          fast will definitely collide because we are using 1 & 2 as steps
          now 2*a = x+ k*L + y
          2x + 2y = x + kL + y
          x + y = kL
          so a is always a multiple of the length of the cycle
          ansd so now you can say that x=z
          lets see
          x = kL - y
          x mod L = (kL - y) mod L
          x mod L = (K times L -y) mod L
          x mod L = L-y
          xmod L = y+z-y =z
          that's why when after collision you move x times
          (both fast and slow(1 1 positions together))..you get the answer


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

    int arr[] = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1};
    int slow = arr[0];
    int fast = arr[0];
    //start together
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
        //slow once..fast twice
    }
    while (slow != fast);
    //got the collision
    //now together one one step
    //set fast to start
    fast = arr[0];
    while (slow != fast) {
        slow = arr[slow];
        fast = arr[fast];
    }
    cout << slow;

    return 0;
}

/*
O/P
9

Time: O(n)
Space: O(1)
*/
