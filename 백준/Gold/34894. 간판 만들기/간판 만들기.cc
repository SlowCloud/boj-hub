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


ll dp[333'333][5];
string uospc = "UOSPC";

int main() {
	cin.tie(0)->sync_with_stdio(0);

	FOR(i, 0, 333'333) FOR(j, 0, 5) dp[i][j] = 1e18;

	int N; cin >> N;
	string s; cin >> s;
	vector<ll> cost(N); for (auto& i : cost) cin >> i;

	FOR(i, 0, N) {
		if (s[i] == 'U') dp[i][0] = cost[i];
		if(i) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
	}

	FOR(i, 1, 5) {
		char now = uospc[i];
		FOR(j, 1, N) {
			dp[j][i] = min(dp[j][i], dp[j - 1][i]);
			if (s[j] == now) {
				dp[j][i] = min(dp[j][i], dp[j - 1][i - 1] + cost[j]);
			}
		}
	}

	ll res = dp[N - 1][4];
	if (res == 1e18) {
		cout << -1;
	}
	else cout << res;

}
