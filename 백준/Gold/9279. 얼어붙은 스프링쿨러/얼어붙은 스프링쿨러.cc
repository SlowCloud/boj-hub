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


vector<pii> G[1111];

int dfs(int now, int prev) {
	bool leaf = true;
	int sum = 0;
	for (auto [w, next] : G[now]) {
		if (next == prev) continue;
		leaf = false;
		sum += min(w, dfs(next, now));
	}
	if (leaf) return 1e5;
	return sum;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, C;

	while (cin >> N >> C) {

		for (auto& g : G) g.clear();
		for (auto& g : G) g.clear();

		FOR(i, 1, N) {
			int u, v, w; cin >> u >> v >> w;
			G[u].push_back({w, v});
			G[v].push_back({w, u});
		}

		cout << dfs(C, -1) << endl;

	}

}

