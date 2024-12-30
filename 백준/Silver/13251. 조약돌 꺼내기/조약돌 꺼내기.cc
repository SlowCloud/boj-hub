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

	ll M; cin >> M;

	if (M == 1) {
		cout << 1; return 0;
	}

	vector<ll> v(M);
	ll total = 0;
	for (auto& i : v) cin >> i, total += i;

	ll K; cin >> K;

	if (K == 1) {
		cout << 1; return 0;
	}

	long double res = 0;

	M *= 1e9;
	for (auto i : v) {
		i *= 1e9;
		long double tmp = 1;
		for (ll k = 0; k < K; k++) {
			ll kk = k * 1e9;
			tmp *= (long double)(i - kk) / (total - k);
			tmp /= 1e9;
		}
		res += tmp;
	}

	cout << setprecision(9) << fixed;

	cout << res;

}
