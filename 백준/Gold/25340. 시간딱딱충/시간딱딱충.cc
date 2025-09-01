#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


struct Node {
	ll a, b, c, d;
};

void solve() {

	int N, T; cin >> N >> T;

	vector<Node> v;
	FOR(i, 0, N) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		v.push_back({ a,b,c,d });
	}
	vector<int> d(N + 1);
	for (auto& i : d) cin >> i;

	ll l = 0, r = 1e9;
	while (l < r) {
		// calc start
		ll m = l + r >> 1;
		ll now = m;
		FOR(i,0,N) {
			const auto& node = v[i];
			now += d[i];
			now = max(now, node.c);
			ll period = (now - node.c) % node.a;
			if (period > node.b - node.d) {
				int gap = node.a - period;
				now += gap;
			}
			now += node.d;
		}
		now += d.back();
		// calc end

		if (now < T) {
			l = m + 1;
		}
		else if (now > T) {
			r = m;
		}
		else {
			l = r = m;
		}
	}

	// calc start
	ll now = l;
	FOR(i,0,N) {
		const auto& node = v[i];
		now += d[i];
		now = max(now, node.c);
		ll period = (now - node.c) % node.a;
		if (period > node.b - node.d) {
			int gap = node.a - period;
			now += gap;
		}
		now += node.d;
	}
	now += d.back();
	// calc end

	cout << (now == T ? "YES" : "NO") << endl;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int T; cin >> T;
	while (T--) solve();

}
