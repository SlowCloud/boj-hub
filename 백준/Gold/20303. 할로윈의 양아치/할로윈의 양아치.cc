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


int candy[33'333];

vector<int> G[33'333];
int vst[33'333];
pii bfs(int s) {
	queue<int> q; q.push(s);
	vst[s] = 1;
	int candies = candy[s];
	int cnt = 1;
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int next : G[now]) {
			if (vst[next]) continue;
			vst[next] = 1;
			q.push(next);
			candies += candy[next];
			cnt++;
		}
	}
	return { cnt, candies };
}

vector<pii> pairs; // children, candies
int dp[3333];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K; cin >> N >> M >> K;

	FOR(i, 1, N + 1) {
		cin >> candy[i];
	}

	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	FOR(i, 1, N + 1) {
		if (!vst[i]) {
			auto p = bfs(i);
			pairs.push_back(p);
		}
	}

	fill(dp, dp + 3333, -1e9);
	dp[0] = 0;
	for (const auto& [cnt, candies] : pairs) {
		for (int i = K - 1; i - cnt >= 0; i--) {
			dp[i] = max(dp[i], dp[i - cnt] + candies);
		}
	}

	int res = 0;
	FOR(i, 0, K) {
		res = max(res, dp[i]);
	}

	cout << res;

}
