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

	int T; cin >> T;
	while (T--) {
		vector<ll> v;
		FOR(i, 0, 3) {
			ll n; cin >> n;
			v.push_back(n);
		}
		sort(rall(v));
		ll D; cin >> D;

		ll total = 0;
		for (auto& i : v) total += i;
		if (total - 2 <= D) {
			cout << 0; continue;
		}

		while (D && v[2] > 0) {
			if (v[0] != v[1]) {
				ll gap = min(D, v[0] - v[1]);
				D -= gap; v[0] -= gap;
			}
			else if (v[1] != v[2]) {
				ll gap = min(D, 2 * (v[1] - v[2]));
				D -= gap;
				v[0] -= gap / 2;
				v[1] -= gap / 2 + (gap & 1);
			}
			else {
				ll gap = min(D, v[0] * 3 - 2);
				D -= gap;
				ll gap_rest = gap % 3;
				v[0] -= gap / 3;
				v[2] -= gap / 3;
				if (gap_rest) v[2]--, gap_rest--;
				v[1] -= gap / 3;
				if (gap_rest) v[1]--, gap_rest--;
			}
		}
		if (v[2] == 0) {
			cout << 0 << endl; continue;
		}
		ll res = 1;
		for (ll n : v) res *= n;
		cout << res << endl;
	}

}
