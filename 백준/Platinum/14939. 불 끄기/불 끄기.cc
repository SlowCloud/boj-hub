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

using vll = vector<ll>;

int board[11][11];

struct Result {
	bool possible;
	int cnt;
};

bool out(int x, int y) {
	return min(x, y) < 0 || max(x, y) >= 10;
}

int m[11][11];

void click(int x, int y) {
	FOR(i, 0, 5) {
		int nx = x + "11102"[i] - '1';
		int ny = y + "02111"[i] - '1';
		if (out(nx, ny)) continue;
		m[nx][ny] ^= 1;
	}
	return;
}

Result check(int bit) {
	memcpy(m, board, sizeof board);

	int cnt = 0;

	FOR(i, 0, 10) {
		if (bit & (1 << i)) {
			click(0, i);
			cnt++;
		}
	}

	FOR(i, 1, 10) {
		FOR(j, 0, 10) {
			if (m[i - 1][j]) {
				click(i, j);
				cnt++;
			}
		}
	}

	FOR(i, 0, 10) FOR(j, 0, 10) {
		if (m[i][j]) return { false, cnt };
	}

	return { true, cnt };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	FOR(i, 0, 10) {
		string s; cin >> s;
		FOR(j, 0, 10) {
			board[i][j] = s[j] == 'O';
		}
	}

	for (int i = 0; i < 1 << 10; i++) {
		Result res = check(i);
		if (res.possible) {
			cout << res.cnt; return 0;
		}
	}

	cout << -1;

}
