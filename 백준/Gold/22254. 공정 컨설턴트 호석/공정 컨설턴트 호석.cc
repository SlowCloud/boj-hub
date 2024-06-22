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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, X; cin >> N >> X;

	vector<ll> v(N);
	for (auto& i : v) cin >> i;

	ll l, r, m;
	l = 1; r = N;

	while (l <= r) {
		m = l + r >> 1;

		priority_queue<ll, vector<ll>, greater<>> pq;
		For(i, 0, m) pq.push(0);

		for (auto& i : v) {
			ll now = pq.top(); pq.pop();
			pq.push(now + i);
		}

		ll big = 0;
		while (pq.size()) {
			big = pq.top(); pq.pop();
		}

		if (X < big) l = m + 1;
		else r = m - 1;

	}

	cout << r + 1;


}