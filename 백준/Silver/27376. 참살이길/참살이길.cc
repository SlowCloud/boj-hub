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


struct Blinker {
	ll x, t, s;
	bool operator < (const Blinker& b) const {
		return x < b.x;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K; cin >> N >> K;

	vector<Blinker> v(K);
	for (auto& b : v) {
		cin >> b.x >> b.t >> b.s;
	}

	sort(all(v));

	ll now = 0;
	ll time = 0;
	for (auto& x : v) {
		time += x.x - now;
		now = x.x;

		time = max(time, x.s);

		ll tick = time - x.s;
		ll red = (tick / x.t) & 1;

		if (red) {
			ll rest = x.t - (tick % x.t);
			time += rest;
		}

	}

	time += (N - now);

	cout << time;

}
