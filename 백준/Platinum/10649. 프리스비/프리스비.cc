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



int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, H;
	cin >> N >> H;

	vector<int> h, w, p;
	h.resize(N);
	w.resize(N);
	p.resize(N);

	FOR(i, 0, N) {
		cin >> h[i] >> w[i] >> p[i];
	}

	vector<int> dp, hs, ws;
	dp.resize(1 << N, -1);
	hs.resize(1 << N);
	ws.resize(1 << N);

	FOR(i, 0, 1 << N) {
		FOR(j, 0, N) {
			if (i & (1 << j)) {
				hs[i] += h[j];
				ws[i] += w[j];
			}
		}
	}

	dp[0] = 1e9;

	FOR(mask, 0, 1 << N) {
		FOR(i, 0, N) {
			if (mask & (1 << i)) {
				int prev = mask ^ (1 << i);
				int power = min(dp[prev], p[i] - ws[prev]);
				if (power >= 0) {
					dp[mask] = max(dp[mask], power);
				}
			}
		}
	}

	int res = -1;
	FOR(mask, 0, 1 << N) {
		if (hs[mask] >= H && dp[mask] >= 0) {
			res = max(res, dp[mask]);
		}
	}

	if (res < 0) cout << "Mark is too tall";
	else cout << res;

}
