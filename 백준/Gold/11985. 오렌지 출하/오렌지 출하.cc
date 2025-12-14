#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



ll dp[22'222];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M, K; cin >> N >> M >> K;

	vector<ll> v(N);
	for (auto& i : v) cin >> i;

	fill(dp, dp + N, LLONG_MAX);

	ll mn = v[0];
	ll mx = v[0];
	FOR(i, 0, M) {
		mn = min(mn, v[i]);
		mx = max(mx, v[i]);
		ll gap = abs(mn - mx);
		ll cnt = i + 1;
		dp[i] = K + cnt * gap;
	}

	FOR(i, 1, N) {
		ll mn = v[i];
		ll mx = v[i];
		FOR(j, i, min(i+M, N)) {
			mn = min(mn, v[j]);
			mx = max(mx, v[j]);
			ll gap = abs(mn - mx);
			ll cnt = j - i + 1;
			dp[j] = min(dp[j], dp[i - 1] + K + cnt * gap);
		}
	}

	cout << dp[N - 1];

}
