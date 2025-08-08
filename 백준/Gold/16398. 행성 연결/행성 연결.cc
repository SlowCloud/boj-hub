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


int vst[1111];
vector<pii> G[1111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			int n; cin >> n;
			G[i].push_back({ -n, j });
		}
	}

	ll res = 0;
	priority_queue<pii> pq; pq.push({ 0, 0 });
	while (pq.size()) {
		const auto [w, now] = pq.top(); pq.pop();
		if (vst[now]) continue;
		vst[now] = 1; res += w;
		for (const auto& next : G[now]) {
			if (vst[next.second]) continue;
			pq.push(next);
		}
	}

	cout << -res;

}
