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
int p[111'111];
int line[111'111];
vector<pii> G[111'111];

void bfs(const int s) {

	fill(d, d + 111'111, 1e9);

	priority_queue<pii, vector<pii>, greater<>> pq;
	pq.push({ 0,s });
	d[s] = 0;
	while (pq.size()) {
		const auto [_, now] = pq.top(); pq.pop();
		for (const auto& [w, next] : G[now]) {
			if (int next_dist = d[now] + w; d[next] > next_dist) {
				d[next] = next_dist;
				pq.push({ next_dist, next });

				p[next] = now;
				line[next] = w;
			}
		}
	}

}

// s,e,w
vector<tuple<int,int,int>> get_lines(const int s, const int a, const int b, const int c) {
	set<tuple<int,int,int>> res;
	for (const auto n : vector<int>{ a,b,c }) {
		for (int now = n; now != s; now = p[now]) {
			int l = p[now], r = now;
			if (l > r) swap(l, r);
			res.insert({ l, r, line[now] });
		}
	}
	return vector<tuple<int,int,int>>(all(res));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back({ c,b });
		G[b].push_back({ c,a });
	}

	int a, b, c; cin >> a >> b >> c;

	int res = 1e9;
	vector<tuple<int, int, int>> result;
	FOR(i, 1, N + 1) {
		bfs(i);
		auto lines = get_lines(i, a, b, c);
		int dist = 0;
		for (auto& [_, __, w] : lines) dist += w;
		if (res > dist) {
			res = dist; result = lines;
		}

	}

	cout << res << ' ' << result.size() << endl;
	for (const auto& [a, b, _] : result) {
		cout << a << ' ' << b << endl;
	}

}
