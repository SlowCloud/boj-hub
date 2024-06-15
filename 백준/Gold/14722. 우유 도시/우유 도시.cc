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

int board[1111][1111];
int dp[1111][1111][3];

bool out(int x, int y, int R, int C) {
	return min(x, y) < 0 || x >= R || y >= C;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N; cin >> N;

	For(i, 0, N) For(j, 0, N) {
		cin >> board[i][j];
	}

	For(i, 0, N) For(j, 0, N) For(k, 0, 3) dp[i][j][k] = -1e9;
	For(i, 0, N) For(j, 0, N) if(board[i][j] == 0) dp[i][j][0] = 1;

	For(i, 0, N) For(j, 0, N) For(k, 0, 3) {
		if (i) {
			dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k]);
			if (board[i][j] == k) {
				int& tmp = dp[i - 1][j][(k + 2) % 3];
				dp[i][j][k] = max(dp[i][j][k], tmp + 1);
			}
		}
		if (j) {
			dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k]);
			if (board[i][j] == k) {
				int& tmp = dp[i][j - 1][(k + 2) % 3];
				dp[i][j][k] = max(dp[i][j][k], tmp + 1);
			}
		}
	}

	int res = 0;
	For(i, 0, N) For(j, 0, N) For(k, 0, 3) {
		res = max(res, dp[i][j][k]);
	}
	cout << res;


}