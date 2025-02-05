#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
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


ll check(ll now) {
	ll two, five;
	two = five = 0;

	ll tmp;

	tmp = now;
	while (tmp >= 2) {
		two += tmp >> 1; tmp >>= 1;
	}

	tmp = now;
	while (tmp >= 5) {
		five += tmp / 5; tmp /= 5;
	}

	return min(two, five);
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll M; cin >> M;

	ll l, r, m;
	l = 5, r = 5e8;

	while (l <= r) {
		m = l + r >> 1;

		ll res = check(m);

		if (res < M) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}

	}

	ll res = check(l);
	
	if (res != M) cout << -1;
	else cout << l;


}
