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


vector<pll> G[5555];
ll vst[5555];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 1, N) {
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back({ c, b });
		G[b].push_back({ c, a });
	}

	queue<int> q; q.push(1);
	fill(vst, vst + 5555, 1e18);
	vst[1] = 0;

	ll mx = 0;
	while (q.size()) {
		int now = q.front(); q.pop();
		for (auto [w, next] : G[now]) {
			if (vst[now] + w < vst[next]) {
				vst[next] = vst[now] + w;
				q.push(next);
				mx = max(mx, vst[next]);
			}
		}
	}

	cout << mx;

}
