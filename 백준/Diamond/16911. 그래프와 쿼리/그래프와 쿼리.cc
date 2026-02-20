#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// gcc things
// #include <ext/rope>

#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
#include <ranges>
#include <chrono>
#include <random>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(auto i=(a);i<(b);i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
#define endl '\n'

constexpr ll powll(ll n, ll k, ll mod = static_cast<ll>(1e9) + 7) {
	ll r = 1 % mod;
	while (k) {
		if (k & 1) r = (r * n) % mod;
		n = (n * n) % mod;
		k >>= 1;
	}
	return r;
};

template <typename T>
constexpr auto OUT(const T R, const T C) {
	return [&](const T x, const T y) -> bool { return (x < 0 || x >= R || y < 0 || y >= C); };
}

template <typename ...Args>
constexpr inline void read(Args&... args) {
	(std::cin >> ... >> args);
}

template <typename ...Args>
constexpr inline void write(Args&& ...args) {
	(std::cout << ... << args);
}


struct Edge {
	int to;
	ll cost;
	ll cap;
	int rev;

	Edge(int to, ll cost) : to(to), cost(cost), rev(0), cap(0) {}
	Edge(int to, ll cost, ll cap, int rev) : to(to), cost(cost), cap(cap), rev(rev) {}
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
		priority_queue<pll, vector<pll>, greater<pll>> pq;
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
		fill(ALL(Q), 0);
		fill(ALL(d), INT_MAX);
		fill(ALL(p), -1);
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
		while (1) {
			spfa(s, e);
			if (p[e] == -1) break;
			ll now = flow_once(s, e);
			f += now;
			c += d[e] * now;
		}
		return { f, c };
	}
};




//namespace Treap {
//	// code from https://github.com/koosaga/olympiad
//}





// editorial & codes from: https://blog.naver.com/jinhan814/222250185888

struct Info { int u, v, state; };

struct UnionFind {
	vector<int> parent, rank;
	stack<Info> S;
	UnionFind(int n) : parent(n), rank(n, 1) {
		iota(parent.begin(), parent.end(), 0);
	}
	int Find(int x) {
		return x == parent[x] ? x : Find(parent[x]);
	}
	bool Union(int a, int b) {
		a = Find(a), b = Find(b);
		if (a == b) return 0;
		if (rank[a] < rank[b]) swap(a, b);
		S.push({ a, b, rank[a] == rank[b] });
		parent[b] = a;
		rank[a] += rank[a] == rank[b];
		return 1;
	}
	void rollback(int cnt) {
		while (cnt--) {
			const auto [a, b, flag] = S.top(); S.pop();
			parent[b] = b;
			rank[a] -= flag;
		}
	}
};

struct SegTree {
	vector <vector<pii>> tree;
	const int n;
	SegTree(int n) : tree(n * 4), n(n) {}
	inline void add(int l, int r, pii info) {
		if (l > r) return;
		add(1, 0, n - 1, l, r, info);
	}
	void add(int node, int s, int e, int l, int r, pii info) {
		if (e < l || r < s) return;
		if (l <= s && e <= r) {
			tree[node].push_back(info);
			return;
		}
		int m = s + e >> 1;
		add(node << 1, s, m, l, r, info);
		add(node << 1 | 1, m + 1, e, l, r, info);
	}
};

void walk(int node, int s, int e, SegTree& seg, vector<pii>& q, UnionFind& uf) {
	int cnt = 0;
	for (const auto [a, b] : seg.tree[node]) cnt += uf.Union(a, b);
	if (s == e) {
		cout << (uf.Find(q[s].first) == uf.Find(q[s].second)) << endl;
		uf.rollback(cnt);
		return;
	}
	int m = s + e >> 1;
	walk(node << 1, s, m, seg, q, uf);
	walk(node << 1 | 1, m + 1, e, seg, q, uf);
	uf.rollback(cnt);
}

inline void walk(SegTree& seg, vector<pii>& q, UnionFind& uf) {
	walk(1, 0, seg.n - 1, seg, q, uf);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	vector<tuple<int,int,int>> queries;
	int cnt = 0; // op == 3 cnt
	FOR(i, 0, M) {
		int op, a, b;
		cin >> op >> a >> b;
		// if (a > b); swap(a, b); // wat
		if (a > b) swap(a, b);
		queries.push_back({op,a,b});
		cnt += op == 3;
	}

	UnionFind uf(N + 1);
	SegTree seg(cnt);
	vector<pii> q; // op == 3 only (a,b)
	map<pii, int> m; // idx mem ((a,b) begin from)
	int now = 0; // idx for q. now <= cnt
	for (const auto [op, a, b] : queries) {
		if (op == 1) { // add edge
			m[{a, b}] = now;
		}
		if (op == 2) { // remove edge
			seg.add(m[{a, b}], now - 1, { a,b });
			m.erase({ a,b });
		}
		if (op == 3) { // query
			q.push_back({ a,b });
			now++;
		}
	}
	// set remain things
	for (const auto [k, v] : m) {
		// const auto [a, b] = k;
		seg.add(v, now - 1, k);
	}

	walk(seg, q, uf);

	return 0;

}
