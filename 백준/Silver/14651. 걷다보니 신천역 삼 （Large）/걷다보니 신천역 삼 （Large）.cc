#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
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


constexpr int MOD = 1e9 + 9;
ll dp[33'334][4];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	dp[1][1] = dp[1][2] = 1;
	FOR(i, 1, 33'333) {
		FOR(j, 0, 3) {
			FOR(k, 0, 3) {
				dp[i+1][(j + k) % 3] += dp[i][j];
				dp[i + 1][(j + k) % 3] %= MOD;
			}
		}
	}

	int N; cin >> N;

	cout << dp[N][0];

}
