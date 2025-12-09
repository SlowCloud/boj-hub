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


int d[111'111];
pii p[111'111];
vector<pii> G[111'111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	int s, e; cin >> s >> e;

	FOR(i, 1, N) {
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({ w,v });
		G[v].push_back({ w,u });
	}

	fill(d, d + 111'111, 1e9);

	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.push({ 0,s });
	d[s] = 0;

	while (pq.size()) {
		const auto [_, now] = pq.top(); pq.pop();
		for (const auto& [w, next] : G[now]) {
			if (int next_dist = d[now] + w; d[next] > next_dist) {
				d[next] = next_dist;
				p[next] = { now, w };
				pq.push({ d[next], next });
			}
		}
	}

	int mx = -1;
	for (int now = e; now != 0; now = p[now].first) {
		mx = max(mx, p[now].second);
	}

	int res = d[e] - mx;
	cout << res;

}
