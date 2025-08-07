#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


constexpr int MOD = 1e9 + 7;
int dp[222'222][5];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 0, 5) {
		dp[0][i] = dp[1][i] = 1;
	}

	FOR(i, 2, N + 1) {
		FOR(j, 0, 4) {
			FOR(k, 0, 4) {
				if (abs(j - k) > 1) {
					dp[i][j] += dp[i - 1][k]; dp[i][j] %= MOD;
				}
			}
			dp[i][j] += dp[i - 1][4]; dp[i][j] %= MOD;
		}
		FOR(j, 0, 4) {
			dp[i][4] += dp[i - 1][j]; dp[i][4] %= MOD;
		}
	}

	int res = 0;
	FOR(i, 0, 5) {
		res += dp[N][i]; res %= MOD;
	}
	cout << res;

}
