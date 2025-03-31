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


string convert(string s) {
	string now = s;
	FOR(i, 0, 4) {
		string tmp;
		FOR(j, 0, 4) {
			tmp.push_back(s[(i + j) % 4]);
		}
		now = min(now, tmp);
	}
	return now;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s;
	FOR(i, 0, 4) {
		char c; cin >> c;
		s.push_back(c);
	}

	s = convert(s);

	set<string> v;
	FOR(i, 1, 10) {
		FOR(j, 1, 10) {
			FOR(k, 1, 10) {
				FOR(l, 1, 10) {
					string tmp;
					tmp.push_back('0' + i);
					tmp.push_back('0' + j);
					tmp.push_back('0' + k);
					tmp.push_back('0' + l);
					v.insert(convert(tmp));
				}
			}
		}
	}
	
	vector<string> vv(all(v));

	int idx = lower_bound(all(vv), s) - vv.begin();
	cout << idx + 1;

}

