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
};

Li_Chao tree;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	tree.init(-2e12, 2e12);

	int Q; cin >> Q;
	while (Q--) {
		int op; cin >> op;
		if(op == 1) {
			ll a, b; cin >> a >> b;
			tree.update(0, { a,b });
		}
		else {
			ll x; cin >> x;
			cout << tree.query(0, x) << endl;
		}
	}

}
