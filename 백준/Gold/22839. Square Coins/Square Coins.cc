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

int dp[22][333];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	dp[0][0] = 1;
	For(i, 1, 18) {
		int now = i * i;
		For(j, 0, 333) {
			if (j - now < 0) continue;
			dp[i][j] = dp[i][j - now] + dp[i - 1][j - now];
		}
		For(j, 0, 333) {
			dp[i][j] += dp[i - 1][j];
		}
	}

	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		cout << dp[17][n] << endl;
	}


}