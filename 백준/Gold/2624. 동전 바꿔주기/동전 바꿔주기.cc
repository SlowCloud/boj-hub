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


map<int, int> dp[111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T, K;
	cin >> T >> K;

	vector<pii> coins;
	FOR(i, 0, K) {
		int a, b; cin >> a >> b;
		coins.push_back({ a,b });
	}
	
	dp[0][0] = 1;

	FOR(i, 0, coins.size()) {
		auto [price, cnt] = coins[i];
		for(auto iter = dp[i].begin(); iter !=dp[i].end(); iter++) {
			auto [now, total] = *iter;
			dp[i + 1][now] += total;
			FOR(c, 1, cnt + 1) {
				int next = now + price * c;
				if (next > T) break;
				dp[i+1][next] += total;
			}
		}
	}

	cout << dp[K][T];

}
