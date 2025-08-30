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


int board[111][111];
int vst[111][111];
int color[111][111];
int d[111][111];

int N;
bool out(const int& x, const int& y) {
	return min(x, y) < 0 || max(x, y) >= N;
}

int island = 2;
void check_island(const int sx, const int sy) {
	memset(vst, 0, sizeof vst);
	queue<pii> q; q.push({ sx, sy });
	vst[sx][sy] = 1;
	board[sx][sy] = island;
	while(q.size()) {
		const auto [x, y] = q.front(); q.pop();
		FOR(i, 0, 4) {
			const int nx = x + "1102"[i] - '1';
			const int ny = y + "0211"[i] - '1';
			if (out(nx, ny)) continue;
			if (board[nx][ny] != 1) continue;
			if (vst[nx][ny]) continue;
			vst[nx][ny] = 1;
			board[nx][ny] = island;
			q.push({ nx,ny });
		}
	}
	island++;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> board[i][j];
		}
	}

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (board[i][j] == 1) {
				check_island(i, j);
			}
		}
	}


	memset(vst, 0, sizeof vst);
	queue<pii> q;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (board[i][j]) {
				q.push({ i,j });
				color[i][j] = board[i][j];
			}
		}
	}

	int cnt = 0;
	int res = 1e9;
	while (q.size()) {
		cnt++;
		for (int t = q.size(); t--;) {
			const auto [x, y] = q.front(); q.pop();
			FOR(i, 0, 4) {
				const int nx = x + "1102"[i] - '1';
				const int ny = y + "0211"[i] - '1';
				if (out(nx, ny)) continue;

				// 같은 땅이면 건너뜀
				if (board[nx][ny]) continue;

				if (color[nx][ny] && color[nx][ny] == color[x][y]) continue;
				if (color[nx][ny] && color[nx][ny] != color[x][y]) {
					res = min(res, d[nx][ny] + cnt - 1); continue;
				}
				color[nx][ny] = color[x][y];
				d[nx][ny] = cnt;
				q.push({ nx,ny });
			}
		}
	}

	cout << res;

}
