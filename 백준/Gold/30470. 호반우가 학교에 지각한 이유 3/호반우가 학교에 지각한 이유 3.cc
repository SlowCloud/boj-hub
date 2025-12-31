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


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	stack<pair<ll, ll>> st; // length, count

	while (N--) {
		ll a, b; cin >> a >> b;

		if (a == 1) {
			if (st.size() && st.top().first == b) st.top().second++;
			else st.push({ b, 1 });
		}
		else if (a == 2) {
			ll limit = st.size() ? max(0ll, st.top().first - b) : 0;
			ll cnt = 0;
			while (st.size() && st.top().first >= limit) {
				cnt += st.top().second;
				st.pop();
			}
			if(cnt) st.push({ limit, cnt });
		}
	}

	ll res = 0;
	while (st.size()) {
		res += st.top().first * st.top().second;
		st.pop();
	}

	cout << res;

}
