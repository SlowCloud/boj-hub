#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

struct smax {

	vector<int> seg;

	smax() : seg(400'004, 0) {}

	void update(int i, int v, int n = 1, int s = 1, int e = 100'000) {
		if (i < s || e < i) return;
		if (s == e) {
			seg[n] = v; return;
		}
		int m = s + e >> 1;
		update(i, v, n << 1, s, m);
		update(i, v, n << 1 | 1, m + 1, e);
		seg[n] = std::max(seg[n << 1], seg[n << 1 | 1]);
	}

	int query(int l, int r, int n = 1, int s = 1, int e = 100'000) {
		if (r < s || e < l) return 0;
		if (l <= s && e <= r) {
			return seg[n];
		}
		int m = s + e >> 1;
		return std::max(query(l, r, n << 1, s, m), query(l, r, n << 1 | 1, m + 1, e));
	}

};

struct smin {

	vector<int> seg;

	smin() : seg(400'004, INT_MAX) {}

	void update(int i, int v, int n = 1, int s = 1, int e = 100'000) {
		if (i < s || e < i) return;
		if (s == e) {
			seg[n] = v; return;
		}
		int m = s + e >> 1;
		update(i, v, n << 1, s, m);
		update(i, v, n << 1 | 1, m + 1, e);
		seg[n] = std::min(seg[n << 1], seg[n << 1 | 1]);
	}

	int query(int l, int r, int n = 1, int s = 1, int e = 100'000) {
		if (r < s || e < l) return 1e9;
		if (l <= s && e <= r) {
			return seg[n];
		}
		int m = s + e >> 1;
		return std::min(query(l, r, n << 1, s, m), query(l, r, n << 1 | 1, m + 1, e));
	}
};

void solve() {

	vector<int> v(100'001);
	iota(all(v), 0);

	smax mx;
	smin mn;

	FOR(i, 1, 100'001) {
		mx.update(i, i);
		mn.update(i, i);
	}

	int N, K; cin >> N >> K;

	while (K--) {
		int Q, A, B; cin >> Q >> A >> B;
		A++; B++;
		if (Q == 0) {
			swap(v[A], v[B]);
			mn.update(A, v[A]);
			mn.update(B, v[B]);
			mx.update(A, v[A]);
			mx.update(B, v[B]);
		}
		else {
			int l = mn.query(A, B);
			int r = mx.query(A, B);
			if (l < A || B < r) {
				cout << "NO";
			}
			else {
				cout << "YES";
			}
			cout << endl;
		}
	}

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		solve();
	}

}

