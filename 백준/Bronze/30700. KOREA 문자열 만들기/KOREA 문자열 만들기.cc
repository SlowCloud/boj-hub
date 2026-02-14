#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#define _USE_MATH_DEFINES

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
#include <ranges>
#include <chrono>
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

	template <typename T>
	struct Node {
		T value;
		int priority, size;
		Node<T>* l = nullptr, * r = nullptr;
		Node(T v) : value(v), priority(rand()), size(1) {}

		void set_left(Node<T>* left) {
			l = left; calc_size();
		}
		void set_right(Node<T>* right) {
			r = right; calc_size();
		}
		void calc_size() {
			size = 1;
			if (l) size += l->size;
			if (r) size += r->size;
		}
	};

	/// <summary>
	/// 값보다 작은 노드와 크거나 같은 노드로 분리
	/// </summary>
	/// <typeparam name="T">타입</typeparam>
	/// <param name="root">루트 노드</param>
	/// <param name="value">값</param>
	/// <returns></returns>
	template <typename T>
	pair<Node<T>*, Node<T>*> split(Node<T>* root, T value) {
		if (root == nullptr) return { nullptr, nullptr };
		if (root->value < value) {
			auto r_sub = split(root->r, value);
			root->set_right(r_sub.first);
			return { root, r_sub.second };
		}
		else {
			auto l_sub = split(root->l, value);
			root->set_left(l_sub.second);
			return { l_sub.first, root };
		}
	}

	/// <summary>
	/// 트립(treap) 자료구조에 주어진 노드를 삽입합니다.
	/// 이 함수는 이진 탐색 트리(BST)와 힙(우선순위) 속성을 유지하며, 필요 시 split 연산을 사용해 새 루트를 반환합니다.
	/// </summary>
	template <typename T>
	Node<T>* insert(Node<T>* root, Node<T>* node) {
		if (root == nullptr) return node;
		if (root->priority < node->priority) {
			auto splitted = split(root, node->value);
			node->set_left(splitted.first);
			node->set_right(splitted.second);
			return node;
		}
		else if (root->value > node->value) {
			root->set_left(insert(root->l, node));
		}
		else {
			root->set_right(insert(root->r, node));
		}
		return root;
	}

	/// <summary>
	/// 순서 변경 없이 합칠 때 사용
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	template <typename T>
	Node<T>* merge(Node<T>* a, Node<T>* b) {
		if (a == nullptr) return b;
		if (b == nullptr) return a;
		if (a->priority < b->priority) {
			b->set_left(merge(a, b->l));
			return b;
		}
		else {
			a->set_right(merge(a->r, b));
			return a;
		}
	}

	//template <typename T, typename... Args>
	//Node<T>* merge(Node<T>* first, Args... args) {
	//	return merge(first, second, merge(args...));
	//}

	/// <summary>
	/// 1-based
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="root"></param>
	/// <param name="k"></param>
	/// <returns></returns>
	template <typename T>
	Node<T>* kth(Node<T>* root, int k) {
		int left_size = 0;
		if (root->l != nullptr) left_size = root->l->size;
		if (k <= left_size) return kth(root->l, k);
		if (k == left_size + 1) return root;
		return kth(root->r, k - left_size - 1);
	}

	template <typename T>
	int count_less_than(Node<T>* root, T value) {
		if (root == nullptr) return 0;
		if (root->value >= value) {
			return count_less_than(root->l, value);
		}
		int left_size = root->l ? root->l->size : 0;
		return left_size + 1 + count_less_than(root->r, value);
	}

	template <typename T>
	void walk_preorder(Node<T>* root, function<void(T)> f) {
		if (root == nullptr) return;
		if (root->l) walk_preorder(root->l, f);
		f(root->value);
		if (root->r) walk_preorder(root->r, f);
	}
}



const string korea = "KOREA";

int main() {
	cin.tie(0)->sync_with_stdio(0);


	string s; cin >> s;

	int res = 0;

	int idx = 0;
	int cnt = 0;
	FOR(i, 0, s.size()) {
		if (s[i] == korea[idx]) {
			idx = (idx + 1) % korea.size();
			cnt++;
		}
	}
	res = max(res, cnt);

	cout << res;

}



