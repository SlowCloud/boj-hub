#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


vector<int> G[333'333];
vector<pii> edges;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	FOR(i, 1, N) {
		int a, b; cin >> a >> b;
		if (a > b) swap(a, b);
		G[a].push_back(b);
		G[b].push_back(a);
		edges.push_back({ a,b });
	}

	ll res = 0;
	for (const auto [u, v] : edges) {
		const ll l = G[u].size() - 1, r = G[v].size() - 1;
		const ll tmp = (l * (l - 1) / 2ll) * (r * (r - 1) / 2ll);
		res += tmp;
	}
	cout << res;
	

}
