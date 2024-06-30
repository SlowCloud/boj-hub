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


int dp[555][77'778]; // 길이, 시작점 = 개수

int main() {
	cin.tie(0)->sync_with_stdio(0);

	dp[1][1] = 1;

	ll next = 1;
	for (ll i = 1; i < 555; i++) {
		for (ll j = next; j < 77'777; j++) {
			for (ll k = j * j + 1; k < 77'777; k++) {
				dp[i + 1][k] += dp[i][j];
			}
		}
		next = next * next + 1;
		if (next >= 77'777) break;
	}

	int T; cin >> T;
	while (T--) {
		int a, b; cin >> a >> b;
		cout << dp[b][a] << endl;
	}

}