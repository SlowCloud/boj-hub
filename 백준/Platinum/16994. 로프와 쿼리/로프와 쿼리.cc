#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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


namespace treap {
	// generated at caterpillow.github.io/byot

	// requires <random>
	mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
	using ptr = struct Node*;

	struct Node {

		int key;
		int sz;
		int pri;
		ptr l, r;

		Node() {
			pri = mt();
			sz = 0;
			l = r = nullptr;
		}

		Node(int key) : key(key) {
			pri = mt();
			sz = 1;
			l = r = nullptr;
		}

		~Node() {
			delete l;
			delete r;
		}
	};

	int sz(ptr n) { return n ? n->sz : 0; };

	ptr pull(ptr n) {
		if (!n) return nullptr;
		n->sz = sz(n->l) + 1 + sz(n->r);
		return n;
	}

	ptr merge(ptr l, ptr r) {
		if (!l || !r) return l ? l : r;
		if (l->pri > r->pri) return l->r = merge(l->r, r), pull(l);
		else return r->l = merge(l, r->l), pull(r);
	}

	// (-inf, k) and [k, inf)
	pair<ptr, ptr> split(ptr n, int k) {
		if (!n) return { nullptr, nullptr };
		if (k <= n->key) {
			auto [l, r] = split(n->l, k);
			n->l = r;
			return { l, pull(n) };
		}
		else {
			auto [l, r] = split(n->r, k);
			n->r = l;
			return { pull(n), r };
		}
	}

	// cuts out [lo, hi)
	tuple<ptr, ptr, ptr> split(ptr n, int lo, int hi) {
		auto [lm, r] = split(n, hi);
		auto [l, m] = split(lm, lo);
		return { l, m, r };
	}

	ptr find(ptr n, int k) {
		if (!n) return 0;
		if (n->key == k) return n;
		if (k <= n->key) return find(n->l, k);
		else return find(n->r, k);
	}

	ptr findi(ptr n, int i) {
		if (!n) return 0;
		if (sz(n->l) == i) return n;
		if (i < sz(n->l)) return findi(n->l, i);
		else return findi(n->r, i - sz(n->l) - 1);
	}

	// only insert single nodes
	void ins(ptr& n, ptr it) {
		if (!n) { n = it; return; }
		if (n->pri < it->pri) {
			auto [l, r] = split(n, it->key);
			it->l = l, it->r = r, n = it;
		}
		else if (it->key <= n->key) ins(n->l, it);
		else ins(n->r, it);
		pull(n);
	}

	// (-inf, i) and [i, inf)
	pair<ptr, ptr> spliti(ptr n, int i) {
		if (!n) return { nullptr, nullptr };
		if (i <= sz(n->l)) {
			auto [l, r] = spliti(n->l, i);
			n->l = r;
			return { l, pull(n) };
		}
		else {
			auto [l, r] = spliti(n->r, i - 1 - sz(n->l));
			n->r = l;
			return { pull(n), r };
		}
	}

	// cuts out [lo, hi)
	tuple<ptr, ptr, ptr> spliti(ptr n, int lo, int hi) {
		auto [lm, r] = spliti(n, hi);
		auto [l, m] = spliti(lm, lo);
		return { l, m, r };
	}

	// rotates treap such that index i is at the start
	void rotate(ptr& n, int i) {
		auto [l, r] = spliti(n, i);
		n = merge(r, l);
	}

	template <typename Op>
	void tour(ptr n, Op op) {
		stack<ptr> stk;
		while (n || !stk.empty()) {
			for (; n; n = n->l) stk.push(n);
			n = stk.top(); stk.pop();
			op(n);
			n = n->r;
		}
	}
}




int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s; cin >> s;

	treap::ptr root = nullptr;

	FOR(i, 0, s.size()) {
		treap::ins(root, new treap::Node(i));
	}

	int Q; cin >> Q;
	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int x, y; read(x, y);
			auto [l,m,r] = treap::spliti(root, x, y + 1);
			treap::merge(treap::merge(m, l), r);
		}
		else if (op == 2) {
			int x, y; read(x, y);
			auto [l,m,r] = treap::spliti(root, x, y + 1);
			treap::merge(treap::merge(l, r), m);
		}
		else {
			int x; cin >> x;
			//treap::tour(root, [&s](treap::ptr p) -> void {
			//	cout << s[p->key];
			//});
			//cout << endl;
			cout << s[treap::findi(root, x)->key] << endl;
		}
	}


}
