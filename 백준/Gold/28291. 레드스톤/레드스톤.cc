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

#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'

#define POWLL(mod) [](ll n, ll k) { ll r = 1 % mod; while (k) { if (k & 1) r = (r * n) % mod; n = (n * n) % mod; k >>= 1; } return r; }

template <typename T>
constexpr auto OUT(const T R, const T C) {
	return [&](const T x, const T y) -> bool { return (x >= 0 && x < R && y >= 0 && y < C); };
}

struct Edge {
	int to;
	ll cost;
	ll cap;
	int rev;

	Edge(int to, ll cost): to(to), cost(cost), rev(0), cap(0) {}
	Edge(int to, ll cost, ll cap, int rev): to(to), cost(cost), cap(cap), rev(rev) {}
};

class Graph {
public:
	int n;
	vector<vector<Edge>> adj;
	Graph(int n) : n(n), adj(n) {}

	void add_edge(int u, int v) {
		add_edge(u, v, 1ll);
	}

	void add_edge(int u, int v, ll cost) {
		adj[u].push_back(Edge{ v,cost });
	}

	vector<ll> dijkstra(const int s) const {
		vector<ll> d(n, -1);
		priority_queue<pll, vector<pll>, greater<>> pq;
		pq.push({ 0,s });
		d[s] = 0;
		while (pq.size()) {
			auto [_, now] = pq.top(); pq.pop();
			for (const auto& next : adj[now]) {
				if (d[next.to] == -1 || d[next.to] > d[now] + next.cost) {
					d[next.to] = d[now] + next.cost;
					pq.push({ d[next.to], next.to });
				}
			}
		}
		return d;
	}

};

class MCMF : public Graph {
private:

	vector<int> p;
	vector<ll> d;
	vector<int> Q;
	vector<int> idx;


	void spfa(const int s, const int e) {
		fill(all(Q), 0);
		fill(all(d), INT_MAX);
		fill(all(p), -1);
		queue<int> q;
		q.push(s);
		d[s] = 0;
		while (q.size()) {
			int now = q.front(); q.pop();
			Q[now] = 0;
			FOR(i, 0, adj[now].size()) {
				const auto& next = adj[now][i];
				if (next.cap <= 0) continue;
				if (d[next.to] > d[now] + next.cost) {
					d[next.to] = d[now] + next.cost;
					p[next.to] = now;
					idx[next.to] = i;
					if (!Q[next.to]) {
						Q[next.to] = 1;
						q.push(next.to);
					}
				}
			}
		}
	}
	ll flow_once(const int s, const int e) {
		ll f = LLONG_MAX;
		for (int now = e; now != s; now = p[now]) {
			f = min(f, adj[p[now]][idx[now]].cap);
		}
		for (int now = e; now != s; now = p[now]) {
			adj[p[now]][idx[now]].cap -= f;
			adj[now][adj[p[now]][idx[now]].rev].cap += f;
		}
		return f;
	}

public:
	MCMF(int n) : Graph(n), p(n), d(n), Q(n), idx(n) {}

	void add_edge(int u, int v, ll cost, ll cap) {
		adj[u].push_back(Edge{ v,cost,cap,(int)adj[v].size() });
		adj[v].push_back(Edge{ u,-cost,0,(int)adj[u].size() - 1 });
	}

	pair<ll, ll> total_flow(const int s, const int e) {
		ll f = 0;
		ll c = 0;
		while(1) {
			spfa(s, e);
			if (p[e] == -1) break;
			ll now = flow_once(s, e);
			f += now;
			c += d[e] * now;
		}
		return { f, c };
	}
};




int board[55][55];
int vst[55][55];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int W, H; cin >> W >> H;
	int N; cin >> N;

	vector<pii> block, lamp;

	FOR(_, 0, N) {
		string s; cin >> s;
		int x, y; cin >> x >> y;
		board[x][y] = 1;

		if (s == "redstone_block") {
			vst[x][y] = 1;
			block.push_back({ x,y });
		}
		else if (s == "redstone_lamp") {
			board[x][y] = 2;
			lamp.push_back({ x,y });
		}
	}

	queue<pii> q;
	for (const auto& b : block) {
		q.push(b);
	}

	const auto out = OUT(W, H);
	
	FOR(_, 0, 15) {
		for (auto t = q.size();t--;) {
			const auto [x, y] = q.front(); q.pop();
			FOR(i, 0, 4) {
				int nx = x + "1102"[i] - '1';
				int ny = y + "0211"[i] - '1';
				if (out(nx, ny)) continue;
				if (board[nx][ny] == 0) continue;
				if (vst[nx][ny]) continue;
				vst[nx][ny] = 1;
				if (board[nx][ny] == 1) {
					q.push({ nx,ny });
				}
			}
		}
	}

	bool res = ranges::all_of(all(lamp), [](const pii& p) -> bool {
		return vst[p.first][p.second];
	});

	cout << (res ? "success" : "failed") << endl;

}
