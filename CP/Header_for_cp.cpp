#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007;
typedef long long ll;
typedef unsigned long long ull;

/*
int binary_to_decimal(string &str)
{
	int n = stoi(str);
	int pow = 1;
	int ans = 0;
	while (n > 0)
	{
		ans += (n % 10) * pow;
		pow *= 2;
		n /= 10;
	}
	return ans;
}
*/
void binary_to_decimal(string num){
	int t = stoi(num, 0, 2);
	cout << t;
}
/*
string decimal_to_binary(int n)
{
	string str;
	while (n > 0)
	{
		string s = to_string(n % 2);
		str += s;
		n /= 2;
	}
	return str;
}
*/
void decimal_to_binary(int n){
	while (n > 0){
		cout<<n % 2;
		n /= 2;
	}
}
int main() {

	cout << fixed;
	cout << setprecision(2);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ull n;
	cin >> n;
	cout << n;

	return 0;
}
