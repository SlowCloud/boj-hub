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


int board[1111][1111];
int dp[1111][1111];

constexpr int MOD = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int R, C; cin >>R>>C;

	FOR(i, 0, R) FOR(j, 0, C) {
		cin >> board[i][j];
	}

	FOR(i, 0, C) {
		dp[R - 1][i] = board[R - 1][i];
	}

	for (int i = R - 2; i >= 0; i--) {
		FOR(j, 0, C) {
			if (board[i][j] == 0) continue;
			FOR(k, -1, 2) {
				int c = j + k;
				if (c < 0 || c >= C) continue;
				dp[i][j] += dp[i + 1][c];
				dp[i][j] %= MOD;
			}
		}
	}

	int res = 0;
	FOR(i, 0, C) {
		res += dp[0][i];
		res %= MOD;
	}
	cout << res;

}
