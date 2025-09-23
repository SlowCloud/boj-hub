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


vector<pii> G[1111];
int vst[1111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K; cin >> N >> M >> K;

	priority_queue<pii, vector<pii>, greater<>> q;
	FOR(i, 0, K) {
		int n; cin >> n;
		q.push({ 0, n });
	}

	FOR(i, 0, M) {
		int u, v, w; cin >> u >> v >> w;
		G[u].push_back({ w,v });
		G[v].push_back({ w,u });
	}

	int res = 0;
	while (q.size()) {
		const auto [w, now] = q.top(); q.pop();
		if (vst[now]) continue;
		vst[now] = 1; res += w;
		for (const auto& edge : G[now]) {
			if (vst[edge.second]) continue;
			q.push(edge);
		}
	}

	cout << res;

}
