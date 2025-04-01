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

	string s; cin >> s;

	if (s[0] != '0') {
		cout << s;
	}
	else {
		// 16
		if (s.size() > 2 && s[1] == 'x') {
			s = s.substr(2);
			int res = 0;
			for (char c : s) {
				res <<= 4;
				if (isdigit(c)) {
					res += c - '0';
				}
				else {
					res += c - 'a' + 10;
				}
			}
			cout << res;
		}
		// 8
		else {
			s = s.substr(1);
			int res = 0;
			for (char c : s) {
				res <<= 3;
				res += c - '0';
			}
			cout << res;
		}
	}
	

}

