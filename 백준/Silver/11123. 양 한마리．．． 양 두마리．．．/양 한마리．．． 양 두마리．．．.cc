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


char board[111][111];
int vst[111][111];

bool out(int x, int y, int R, int C) {
	return min(x, y) < 0 || x >= R || y >= C;
}

void bfs(int sx, int sy, int R, int C) {
	queue<tuple<int, int>> q; q.push({ sx, sy });
	vst[sx][sy] = 1;

	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		FOR(i, 0, 4) {
			int nx = x + "1102"[i] - '1';
			int ny = y + "0211"[i] - '1';
			if (out(nx, ny, R, C)) continue;
			if (vst[nx][ny]) continue;
			vst[nx][ny] = 1; q.push({ nx,ny });
		}
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		memset(board, 0, sizeof board);
		memset(vst, 0, sizeof vst);
		int R, C; cin >> R >> C;

		FOR(i, 0, R) {
			FOR(j, 0, C) {
				cin >> board[i][j];
				vst[i][j] = board[i][j] == '.';
			}
		}

		int res = 0;
		FOR(i, 0, R) {
			FOR(j, 0, C) {
				if (!vst[i][j]) {
					res++;
					bfs(i, j, R, C);
				}
			}
		}

		cout << res << endl;

	}


}

