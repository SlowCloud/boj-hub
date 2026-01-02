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

#define FOR_(type,i, a, b) for(type i=a;i<b;i++)
#define FOR(i,a,b) FOR_(int,i,a,b)
#define FORLL(i,a,b) FOR_(ll,i,a,b)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'


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



inline int to_index(int x, int y, const int N) {
	return x * N + y;
}



char m[55][55];
MCMF g(3333);
constexpr int S = 3000, E = 3001;
map<string, int> score = {
	{"AA", 10},
	{"AB", 8},
	{"AC", 7},
	{"AD", 5},
	{"AF", 1},

	{"BB", 6},
	{"BC", 4},
	{"BD", 3},
	{"BF", 1},

	{"CC", 3},
	{"CD", 2},
	{"CF", 1},

	{"DD", 2},
	{"DF", 1},

	{"FF", 0},
};

int get_score(char a, char b) {
	if (a > b) swap(a, b);
	string s = "";
	s += a;
	s += b;
	return score[s];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	FOR(i, 0, N) {
		FOR(j, 0, M) {
			cin >> m[i][j];
		}
	}

	FOR(i, 0, N) {
		FOR(j, 0, M) {
			if ((i + j) % 2) {
				g.add_edge(to_index(i, j, M), E, 0, 1);
			}
			else {
				g.add_edge(S, to_index(i, j, M), 0, 1);
				g.add_edge(to_index(i, j, M), E, 0, 1); // 미선택으로 빠질 수 있게.
				FOR(k, 0, 4) {
					int ni = i + "1102"[k] - '1';
					int nj = j + "0211"[k] - '1';
					if (ni < 0 || ni >= N || nj < 0 || nj >= M) continue;
					g.add_edge(to_index(i, j, M), to_index(ni, nj, M), -get_score(m[i][j], m[ni][nj]), 1);
				}
			}
		}
	}

	auto [flow, cost] = g.total_flow(S, E);
	cout << -cost;

}
