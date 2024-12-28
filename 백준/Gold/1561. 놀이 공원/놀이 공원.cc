#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
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

	int N, M; cin >> N >> M;
	
	if (N <= M) {
		cout << N; return 0;
	}
	N -= M;

	vector<int> v(M);
	int all = 0;
	for (auto& i : v) cin >> i, all += i;

	ll l, r, m;
	l = 1, r = 1e12;

	while (l <= r) {
		ll m = l + r >> 1;

		ll now = 0;
		for (auto& i : v) now += m / i;

		if (now >= N) r = m - 1;
		else l = m + 1;
	}

	ll t = r;
	ll done = 0;
	for (auto& i : v) done += t / i;
	int rest = N - done;

	vector<pair<int, int>> nodes;
	FOR(i, 0, v.size()) {
		nodes.push_back({ v[i] - t % v[i], i + 1 });
	}

	sort(all(nodes));
	cout << nodes[rest - 1].second;

}
