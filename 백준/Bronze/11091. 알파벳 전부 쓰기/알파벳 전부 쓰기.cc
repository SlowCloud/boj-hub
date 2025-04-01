#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int main() {
	cin.tie(0)->sync_with_stdio(0);

	string alphabets = "abcdefghijklmnopqrstuvwxyz";
	sort(all(alphabets));

	int T; cin >> T;
	string tmp;
	getline(cin, tmp);

	while (T--) {

		string s;
		getline(cin, s);

		set<char> se;
		for (char c : s) {
			if (isalpha(c)) {
				se.insert(tolower(c));
			}
		}

		if (se.size() == 26) {
			cout << "pangram" << endl;
		}
		else {
			cout << "missing ";
			for (char c : alphabets) {
				if (se.count(c) == 0) {
					cout << c;
				}
			}
			cout << endl;
		}

	}


}

