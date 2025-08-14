#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


void solve() {

	int s, t;
	cin >> s >> t;
	if (s == t) {
		cout << 0 << endl; return;
	}

	queue<pii> q; q.push({ s,t });
	int res = 0;
	while (q.size()) {
		res++;
		for (int t = q.size(); t--;) {
			const auto [a, b] = q.front(); q.pop();
			vector<pii> v{ {a * 2,b + 3}, {a + 1,b} };
			for (const auto& [a, b] : v) {
				if (a > b) continue;
				if (a == b) {
					cout << res << endl; return;
				}
				q.push({ a,b });
			}
		}
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int C; cin >> C;
	while (C--) {
		solve();
	}

}
