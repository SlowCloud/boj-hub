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




template <int BIT_SIZE>
class Trie {
public:
	Trie* next[2];
	int cnt;

	Trie() : cnt(0) {
		next[0] = nullptr;
		next[1] = nullptr;
	}

	void push(int n, int cnt_ = BIT_SIZE) {
		this->cnt++;
		if (cnt_ >= 0) {
			int now = (n >> cnt_) & 1;
			if (next[now] == nullptr) next[now] = new Trie();
			next[now]->push(n, cnt_ - 1);
		}
	}

	void pop(int n, int cnt_ = BIT_SIZE) {
		this->cnt--;
		if (cnt_ >= 0) {
			int now = (n >> cnt_) & 1;
			next[now]->pop(n, cnt_ - 1);
			if (next[now]->cnt == 0) {
				delete next[now];
				next[now] = nullptr;
			}
		}
	}

	ll query(int n, int cnt_ = BIT_SIZE) {
		int now = (n >> cnt_) & 1;
		if (cnt_ == -1) return 0;
		if (next[1 - now] != nullptr) {
			return (1ll << cnt_) | next[1 - now]->query(n, cnt_ - 1);
		}
		else if (next[now] != nullptr) {
			return next[now]->query(n, cnt_ - 1);
		}
		else {
			return n;
		}
	}
};

Trie<31> root;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	root.push(0);

	FOR(i, 0, N) {
		int op, x; cin >> op >> x;
		if (op == 1) {
			root.push(x);
		}
		else if (op == 2) {
			root.pop(x);
		}
		else {
			cout << root.query(x) << endl;
		}
	}

}
