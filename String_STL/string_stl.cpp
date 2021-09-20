#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main()
{
	cout << fixed;
	cout << setprecision(2);

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	string s;
	getline(cin, s);
	//helps with spaces
	cout << s;
	//print directly c++

	string s1;
	cin >> s1;
	//takes only first continuous part

	//assignment
	// string s2 = ""; or
	string s2;
	s2 = "eef";
	cout << s2 << '\n';

	//another 1 line
	string s3 = "eefgh";
	cout << s3 << '\n';

	//string manipulation..for each
	for (auto x : s3)
		cout << x << " ";
	cout << '\n';
	//run till specific index..use for loop
	for (int i = 0; i < 2; i++)
		cout << s3[i];
	cout << '\n';

	//length
	int z = s3.length();
	cout << z << '\n';

	//change any index value..for ex s3 is eefgh
	//change 2 index
	s3[2] = 'k';
	cout << s3 << '\n';

	//concatenate
	s3 += "xyz";
	cout << s3 << '\n';

	//substr
	cout << s3.substr(0, 3) << '\n';
	string k = s3.substr(0, 3);
	cout << k << '\n';

	//find
	s3 = "abcdefgabc"; //just to make things clear
	cout << s3.find("abc") << '\n';
	//gives index of 1st occurence

	cout << s3.find("x") << '\n';
	//return special value: npos

	string given = "c";
	int res = s3.find(given);
	if (res == string::npos)
		cout << "Not found" << '\n';
	//correct way to find out not present
	else
		cout << "Found at Index " << res << '\n';

	//string comparisons c++
	//for abc & abg  g1
	//for abc & ab   g2
	//for abc & abc equal
	string g1 = "abc";
	string g2 = "abc";
	cout << (g1 < g2) << '\n'; //one line
	if (g1 < g2) {
		cout << "G1";
	} else if (g1 == g2) {
		cout << "Equal";
	} else {
		cout << "G2";
	}
	cout << '\n';
	//lexicographic check only happens with equal lengths

	//last way of traversing
	string zz = "fgduh";
	for (auto i = zz.begin(); i != zz.end(); i++)
		cout << *i;

	return 0;
}



/*
Output


eef
eefgh
e e f g h 
ee
5
eekgh
eekghxyz
eek
eek
0
4294967295
Found at Index 2
0
Equal
fgduh
*/


