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



ll dp[1111];
int m[1111];
int mn[1111][1111];
int mx[1111][1111];

int calc(int l, int r) {
	return mx[l][r] - mn[l][r];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 0, N) {
		cin >> m[i];
	}

	FOR(i, 0, N) {
		mn[i][i] = mx[i][i] = m[i];
		FOR(j, i + 1, N) {
			mn[i][j] = min(mn[i][j - 1], m[j]);
			mx[i][j] = max(mx[i][j - 1], m[j]);
		}
	}

	FOR(i, 0, N) {
		dp[i] = calc(0, i);
		FOR(j, 0, i) {
			dp[i] = max(dp[i], dp[j] + calc(j + 1, i));
		}
	}

	cout << dp[N - 1];

}
