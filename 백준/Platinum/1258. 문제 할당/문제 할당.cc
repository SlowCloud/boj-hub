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

// https://www.acmicpc.net/problem/1258
// https://www.acmicpc.net/problem/11495


struct Edge {
	int from;
	int to;
	ll cost;

	Edge(int from, int to, ll cost): from(from), to(to), cost(cost) {}
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
		adj[u].push_back(Edge{ u,v,cost });
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

class MCMF : Graph {
private:

	vector<int> p;
	vector<ll> d;
	vector<int> Q;

	vector<vector<ll>> flow, cap;

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
			for (const Edge& next : adj[now]) {
				if (flow[now][next.to] >= cap[now][next.to]) continue;
				if (p[next.to] == -1 || d[next.to] > d[now] + next.cost) {
					d[next.to] = d[now] + next.cost;
					p[next.to] = now;
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
			f = min(f, cap[p[now]][now] - flow[p[now]][now]);
		}
		for (int now = e; now != s; now = p[now]) {
			flow[p[now]][now] += f;
			flow[now][p[now]] -= f;
		}
		return f;
	}

public:
	MCMF(int n) : Graph(n), p(n), d(n), Q(n), flow(n, vector<ll>(n)), cap(n, vector<ll>(n)) {}

	void add_edge(int u, int v, ll cost, ll cap) {
		Graph::add_edge(u, v, cost);
		Graph::add_edge(v, u, -cost);
		MCMF::cap[u][v] = cap;
	}

	/// <summary>
	/// 플로우 및 코스트 계산 후 반환
	/// </summary>
	/// <param name="s"></param>
	/// <param name="e"></param>
	/// <returns>플로우, 코스트 계산.</returns>
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

MCMF mcmf(333);

int m[111][111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	constexpr int S = 303, E = 304;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> m[i][j];
		}
	}

	FOR(i, 0, N) {
		mcmf.add_edge(S, i, 0, 1);
		mcmf.add_edge(100 + i, E, 0, 1);
		FOR(j, 0, N) {
			mcmf.add_edge(i, 100 + j, m[i][j], 1);
		}
	}

	auto [f, c] = mcmf.total_flow(S, E);

	cout << c;

}
