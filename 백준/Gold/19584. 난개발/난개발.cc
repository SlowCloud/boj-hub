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


ll board[444'444];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	vector<int> x, dots;

	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		x.push_back(b);
		dots.push_back(b);
	}

	sort(all(x));

	for (auto& dot : dots) {
		int now = lower_bound(all(x), dot) - x.begin();
		dot = now * 2;
	}

	FOR(i, 0, M) {
		int a, b, c; cin >> a >> b >> c;
		int s, e;
		s = min(dots[a - 1], dots[b - 1]);
		e = max(dots[a - 1], dots[b - 1]);
		board[s] += c;
		board[e + 1] -= c;
	}

	FOR(i, 1, 444'444) {
		board[i] += board[i-1];
	}

	ll res = 0;

	for (int i = 0; i < 444'444; i++) {
		res = max(res, board[i]);
	}

	cout << res;

}

