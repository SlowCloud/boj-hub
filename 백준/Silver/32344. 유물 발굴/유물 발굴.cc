#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

struct Node {

	ll maxr, minr, maxc, minc;

	Node() {
		maxr = maxc = -1;
		minr = minc = 1e9;
	}

	Node(ll r, ll c) {
		maxr = minr = r;
		maxc = minc = c;
	}

	void update(ll r, ll c) {
		maxr = max(maxr, r);
		minr = min(minr, r);
		maxc = max(maxc, c);
		minc = min(minc, c);
	}

	ll size() const {
		return (maxr - minr + 1) * (maxc - minc + 1);
	}

};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int R, C; cin >> R >> C;

	int N; cin >> N;

	map<int, Node> v;

	FOR(i, 0, N) {
		int a, b, c; cin >> a >> b >> c;
		v[a].update(b, c);
	}

	ll res = 0;
	int idx = 0;
	for(auto& p : v) {
		int i = p.first;
		Node n = p.second;
		if (res < n.size()) {
			res = n.size();
			idx = i;
		}
	}

	cout << idx << ' ' << res;


}
