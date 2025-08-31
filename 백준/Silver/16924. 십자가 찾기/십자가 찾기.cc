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


char board[111][111];
int vst[111][111];
int R, C;

inline bool out(const int r, const int c) {
	return min(r, c) < 0 || r >= R || c >= C;
}

bool check(const int r, const int c, const int k) {

	for (int i = r - k; i <= r + k; i++) {
		for (int j = c - k; j <= c + k; j++) {
			if (out(r, j) || out(i, c)) return false;
			if (board[r][j] != '*' || board[i][c] != '*') return false;
		}
	}
	for (int i = r - k; i <= r + k; i++) {
		for (int j = c - k; j <= c + k; j++) {
			vst[r][j] = vst[i][c] = 1;
		}
	}
	return true;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> C;

	FOR(i, 0, R) {
		FOR(j, 0, C) {
			cin >> board[i][j];
		}
	}

	vector<tuple<int, int, int>> res;
	FOR(i, 1, R - 1) {
		FOR(j, 1, C - 1) {
			FOR(k, 1, min(R, C)) {
				if (check(i, j, k)) {
					res.push_back({ i,j,k });
				}
				else break;
			}
		}
	}

	FOR(i, 0, R) {
		FOR(j, 0, C) {
			if (board[i][j] == '*' && !vst[i][j]) {
				cout << -1; exit(0);
			}
		}
	}

	cout << res.size() << endl;
	for (const auto& t : res) {
		const auto& [a, b, c] = t;
		cout << a + 1 << ' ' << b + 1 << ' ' << c << endl;
	}

}
