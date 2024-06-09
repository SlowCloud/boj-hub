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


ll dp[1111][1111];

constexpr int MOD = 10'007;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	dp[0][0] = 1;

	For(i, 1, 1111) For(j, 0, 1111) {
		dp[i][j] += dp[i - 1][j];
		if (j) dp[i][j] += dp[i - 1][j - 1];
		dp[i][j] %= MOD;
	}

	int a, b; cin >> a >> b;

	cout << dp[a][b];


}