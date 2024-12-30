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

int board[55][55];

void solve() {

	memset(board, 0, sizeof board);
	int R, C; cin >> R >> C;

	int H = -1;
	FOR(i, 0, R) {
		string s; cin >> s;
		FOR(j, 0, C) {
			char c = s[j];
			board[i][j] = c - '0';
			H = max(H, board[i][j]);
		}
	}

	int res = 0;
	FOR(i, 0, R) FOR(j, 0, C) {
		if (board[i][j]) res += 2;
	}

	auto out = [&](int x, int y) -> bool {
		return min(x, y) < 0 || x >= R || y >= C;
	};

	FOR(h, 1, H + 1) {
		FOR(i, 0, R) {
			FOR(j, 0, C) {
				int now = board[i][j];
				if (now < h) continue;
				FOR(d, 0, 4) {
					int nx = i + "1102"[d] - '1';
					int ny = j + "0211"[d] - '1';
					if (out(nx, ny) || board[nx][ny] < h) {
						res++;
					}
				}
			}
		}
	}

	cout << res << endl;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		solve();
	}

}
