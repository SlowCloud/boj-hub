#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


struct Line {
	ll w, b; // wx + b
	inline ll get(const ll x) const {
		return w * x + b;
	}
};

struct Node {
	int l, r; // next
	ll s, e; // range
	Line line;
};

// 아래로 볼록
struct Li_Chao {
	const ll inf = 9e18;
	vector<Node> tree;
	void init(ll s, ll e) {
		tree.push_back({ -1, -1, s, e, {0, -inf} });
	}
	void update(int node, Line v) {
		ll s = tree[node].s, e = tree[node].e;
		ll m = s + e >> 1;

		Line low = tree[node].line, high = v;
		if (low.get(s) > high.get(s)) swap(low, high);

		if (low.get(e) <= high.get(e)) {
			tree[node].line = high; return;
		}

		if (low.get(m) < high.get(m)) {
			tree[node].line = high;
			if (tree[node].r == -1) {
				tree[node].r = tree.size();
				tree.push_back({ -1, -1, m + 1, e, {0, -inf} });
			}
			update(tree[node].r, low);
		}
		else {
			tree[node].line = low;
			if (tree[node].l == -1) {
				tree[node].l = tree.size();
				tree.push_back({ -1, -1, s, m, {0, -inf} });
			}
			update(tree[node].l, high);
		}

	}
	ll query(int node, ll x) const {
		if (node == -1) return -inf;
		ll s = tree[node].s, e = tree[node].e;
		ll m = s + e >> 1;
		if (x <= m) return max(tree[node].line.get(x), query(tree[node].l, x));
		else return max(tree[node].line.get(x), query(tree[node].r, x));
	}
	Line query_line(int node, ll x) const {
		if (node == -1) return { 0, -inf };
		ll s = tree[node].s, e = tree[node].e;
		ll m = s + e >> 1;
		if (x <= m) {
			if (tree[node].line.get(x) >= query(tree[node].l, x)) {
				return tree[node].line;
			}
			else {
				return query_line(tree[node].l, x);
			}
		}
		else {
			if (tree[node].line.get(x) >= query(tree[node].r, x)) {
				return tree[node].line;
			}
			else {
				return query_line(tree[node].r, x);
			}
		}
	}
};

Li_Chao tree;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	tree.init(-2e12, 2e12);

	int N, Q; cin >> N >> Q;

	FOR(i, 0, N) {
		ll a, b; cin >> a >> b;
		tree.update(0, { a, b });
	}


	ll l = -2e12, r = 2e12;
	while (l <= r) {
		ll m = l + r >> 1;
		Line line = tree.query_line(0, m);
		if (line.w == 1) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	ll multiplier_idx = l; // w > 1 from here

	while (Q--) {
		ll x, y; cin >> x >> y;
		ll cnt = 0;
		while (x < y) {
			if (x < multiplier_idx) {
				Line line = tree.query_line(0, x);
				if (line.get(x) <= x) {
					cnt = -1; break;
				}
				ll gap = min(y, multiplier_idx) - x;
				ll tmp = (gap + line.b - 1) / line.b;
				cnt += tmp;
				x += tmp * line.b;
			}
			else {
				ll next = tree.query(0, x);
				if (next <= x) {
					cnt = -1; break;
				}
				x = next;
				cnt++;
			}
		}
		cout << cnt << endl;
	}

}
