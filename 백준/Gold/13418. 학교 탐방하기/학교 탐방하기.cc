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

	int N, M; cin >> N >> M;

	vector<pii> up, down;

	FOR(i, 0, M + 1) {
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back({ c,b });
		G[b].push_back({ c,a });
	}

	priority_queue<pii> bpq; bpq.push({ 0,0 });
	memset(vst, 0, sizeof vst);
	int big = 0;
	while (bpq.size()) {
		auto [w, now] = bpq.top(); bpq.pop();
		if (vst[now]) continue;
		vst[now] = 1;
		big += w;
		for (auto next : G[now]) {
			if (vst[next.second]) continue;
			bpq.push(next);
		}
	}

	priority_queue<pii, vector<pii>, greater<>> spq; spq.push({ 0,0 });
	memset(vst, 0, sizeof vst);
	int small = 0;
	while (spq.size()) {
		auto [w, now] = spq.top(); spq.pop();
		if (vst[now]) continue;
		vst[now] = 1;
		small += w;
		for (auto next : G[now]) {
			if (vst[next.second]) continue;
			spq.push(next);
		}
	}

	// 내리막이 1이어서 뒤집어줘야 함..
	big = N - big;
	small = N - small;

	cout << small * small - big * big << endl;

}
