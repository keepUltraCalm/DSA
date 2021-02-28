//Q...
//Sieve_of_Eratosthenes!!

//we need to print all prime numbers from 0 to that number
//now the question is how we can we do that??

//logic..
//ok..so what we do is..first we create a boolean array
//its size is n+1...now why n+1??
//because array index stats from 0..so the last indx is n
//now, we initialize all the index from 2 to n as true..you can leave 0 and 1 index..
//as we are not going to use these..because they are not prime numbers

#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void sieve(int n) {
	bool arr[n + 1];
	for (int i = 0; i < n + 1; i++) {
		arr[i] = true;
	}
	for (int i = 2; i * i <= n; i++) {
		//starting from 2..as 1 is not prime
		//need to traverse till sqrt n
		//now why till sqrt n??
		//because any number..is in the form a x b
		//now, the lesser of these two numbers will always be <=sqrt of n
		
		if (arr[i] == true) {
			for (int j = 2 * i; j < n + 1; j += i) {
				//j+=i...to make multiples of i
				//and then marking them as false because they are not prime
				arr[j] = false;
			}
		}
	}
	//scope of this i is different
	for (int i = 2; i < n + 1; i++) {
		if (arr[i]) {
			//short form of checking == true
			cout << i << " ";
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//for input & output file

	int n;
	cin >> n;
	sieve(n);
	return 0;
}


//INPUT
//20

//OUTPUT
//2 3 5 7 11 13 17 19
