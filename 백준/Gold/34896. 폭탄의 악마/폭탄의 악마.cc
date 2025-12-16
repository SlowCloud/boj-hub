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


// https://www.acmicpc.net/problem/34896
// R을 이분탐색해서 모든 점을 터뜨릴 수 있을 때, 연쇄폭발 가능한 점의 각 집합들에 대해 최소 비용을 모아 계산하면 된다.

struct Bomb {
	ll position, price;
};

vector<Bomb> bombs;
int vst[222'222];

inline bool out(const int x) {
	return x < 0 || bombs.size() <= x;
}

vector<Bomb> bfs(const int s, const int R) {

	vector<Bomb> visited_bombs;

	queue<int> q; q.push(s);
	visited_bombs.push_back(bombs[s]);
	vst[s] = 1;
	while (q.size()) {
		const auto now = q.front(); q.pop();
		for (int next : {now - 1, now + 1}) {
			if (out(next)) continue;
			if (vst[next]) continue;
			int gap = abs(bombs[now].position - bombs[next].position);
			if (gap > R) continue;
			visited_bombs.push_back(bombs[next]);
			vst[next] = 1;
			q.push(next);
		}
	}

	return visited_bombs;
}

ll get_smallest_price(const vector<Bomb>& g) {

	ll res = 1e18;
	for (const auto& b : g) {
		res = min(res, b.price);
	}
	return res;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	FOR(i, 0, N) {
		int n; cin >> n;
		bombs.push_back({ n });
	}

	FOR(i, 0, N) {
		int c; cin >> c;
		bombs[i].price = c;
	}

	int B; cin >> B;

	sort(all(bombs), [](const Bomb& l, const Bomb& r) -> bool {
		return l.position < r.position;
	});

	int l, r, m;
	l = 1, r = 3e8;
	while (l <= r) {
		m = l + r >> 1;

		vector<vector<Bomb>> bombs_group;
		memset(vst, 0, sizeof vst);
		FOR(i,0,N) {
			if(!vst[i]) bombs_group.push_back(bfs(i, m));
		}

		ll price = 0;
		for (const auto& g : bombs_group) price += get_smallest_price(g);

		if (price > B) l = m + 1;
		else r = m - 1;

	}

	cout << l;

}
