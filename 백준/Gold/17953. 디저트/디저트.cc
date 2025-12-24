#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int m[111'111][11];
int dp[111'111][11];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	FOR(i, 0, M) {
		FOR(j, 0, N) {
			cin >> m[j][i];
		}
	}

	FOR(i, 0, M) {
		dp[0][i] = m[0][i];
	}

	FOR(i, 1, N) {
		FOR(j, 0, M) {
			FOR(k, 0, M) {
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + (j == k? m[i][j] / 2 : m[i][j]));
			}
		}
	}

	int res = 0;
	FOR(i, 0, M) {
		res = max(res, dp[N - 1][i]);
	}

	cout << res;

}
