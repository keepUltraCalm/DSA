//count frequencies of elements in strings in sorted order

#include <bits/stdc++.h>
using namespace std;
int main() {
	string s = "geeksforgeeks";
	int ch[26] = {0};
	for (int i = 0; i < s.length(); i++)
		++ch[s[i] - 'a']; //assuming only lowecase given
	for (int i = 0; i < 26; i++) {
		if (ch[i] != 0) {
			cout << ch[i] << " " << char(i + (int)'a');
			cout << '\n';
		}
	}
	return 0;
}
