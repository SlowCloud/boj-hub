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




//namespace Treap {
//	// code from https://github.com/koosaga/olympiad
//}






ll m[2'222'222];

constexpr ll sq = 1444;
//constexpr ll sq = 2;
map<ll, ll> bucket[2'222'222 / sq];
ll global[2'222'222 / sq];
int N, K;

// O(log(sqrt(N))
void add(int idx) {
	ll now = m[idx] % K;
	bucket[idx / sq][now]--;
	if (bucket[idx / sq][now] == 0) {
		bucket[idx / sq].erase(now);
	}
	m[idx]++;
	now = (now + 1) % K;
	bucket[idx / sq][now]++;
}

// O(1)
void add_bucket(int bucket_idx) {
	global[bucket_idx]++;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;

	FOR(i, 0, N) {
		ll n; cin >> n;
		m[i] = n;
		bucket[i / sq][n % K]++;
	}

	int Q; cin >> Q;
	while (Q--) {
		int op, s, e; read(op, s, e);
		s--; e--;
		if (op == 1) {
			while (s % sq && s <= e) {
				add(s);
				s++;
			}
			while (s + sq <= e + 1) {
				add_bucket(s / sq);
				s += sq;
			}
			while (s <= e) {
				add(s);
				s++;
			}
			//cout << "UPDATED:: ";
			//FOR(i, 0, N) {
			//	cout << (m[i] + global[i/sq]) %K << ' ';
			//}
			//cout << endl;
		}
		else {
			ll res = 0;
			while (s % sq && s <= e) {
				res += (m[s] + global[s/sq]) % K;
				s++;
			}
			while (s + sq <= e + 1) {
				for (const auto& p : bucket[s / sq]) {
					res += (p.first + global[s / sq]) % K * p.second;
				}
				s += sq;
			}
			while (s <= e) {
				res += (m[s] + global[s / sq]) % K;
				s++;
			}
			cout << res << endl;

		}
	}


}
