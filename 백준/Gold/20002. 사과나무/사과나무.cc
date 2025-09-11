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


int board[333][333];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 1, N + 1) {
		FOR(j, 1, N + 1) {
			cin >> board[i][j];
			board[i][j] += board[i][j - 1];
		}
		FOR(j, 1, N + 1) {
			board[i][j] += board[i - 1][j];
		}
	}

	int res = INT_MIN;
	FOR(k, 0, N) {
		FOR(i, 1, N + 1) {
			FOR(j, 1, N + 1) {
				if (max(i, j) + k > N) continue;
				const int tmp = board[i + k][j + k] - board[i - 1][j + k] - board[i + k][j - 1] + board[i - 1][j - 1];
				res = max(res, tmp);
			}
		}
	}

	cout << res;

}
