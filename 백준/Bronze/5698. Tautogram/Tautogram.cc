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

	while(true) {
		string s;
		getline(cin, s);

		if (s == "*") break;

		stringstream ss(s);

		char c = tolower(s[0]);
		string token;
		bool check = true;
		while (ss >> token) {
			char now = tolower(token[0]);
			if (now != c) {
				check = false; break;
			}
		}

		cout << (check ? "Y" : "N") << endl;

	}

}
