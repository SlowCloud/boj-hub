#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int R, C; cin >> R >> C;

	vector<string> v;
	vector<string> vv;

	FOR(i, 0, R) {
		string s; cin >> s;
		v.push_back(s);
	}

	FOR(i, 0, C) {
		string now;
		FOR(j, 0, R) {
			now += v[j][i];
		}
		vv.push_back(now);
	}

	int l, r, m;
	l = 0; r = R - 1;

	while (l <= r) {
		m = l + r >> 1;

		map<string, int> cnt;
		FOR(i, 0, C) {
			cnt[vv[i].substr(m)]++;
		}

		bool possible = true;
		for (auto& p : cnt) {
			if (p.second > 1) {
				possible = false; break;
			}
		}

		if (possible) l = m + 1;
		else r = m - 1;
	}

	cout << r;


}
