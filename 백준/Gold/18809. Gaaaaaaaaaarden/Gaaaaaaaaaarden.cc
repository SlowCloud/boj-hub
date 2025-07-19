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



int m[55][55];
int board[55][55][2];
int N, M;
int G, R;

struct Node {
	int x, y, color;
};

bool out(const int x, const int y) {
	return min(x, y) < 0 || x >= N || y >= M;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> G >> R;

	vector<pii> drops;

	FOR(i, 0, N) {
		FOR(j, 0, M) {
			int now; cin >> now;
			m[i][j] = now;
			if (now == 2) {
				drops.push_back({ i, j });
			}
		}
	}

	vector<int> v(drops.size());
	FOR(i, 0, G) {
		v[i] = 1;
	}
	FOR(i, G, G + R) {
		v[i] = 2;
	}
	sort(all(v));

	int res = 0;

	do {

		// setup queue & board
		memset(board, 0, sizeof board);
		queue<Node> q;
		FOR(i, 0, v.size()) {
			if (v[i] == 0) continue;
			auto now = drops[i];
			q.push({ now.first, now.second, v[i] - 1 });
			board[now.first][now.second][v[i] - 1] = 1;
		}

		// spread
		int round = 1;
		while (q.size()) {
			round++;
			for (int t = q.size(); t--;) {
				Node now = q.front(); q.pop();
				if (board[now.x][now.y][0] == board[now.x][now.y][1]) continue;
				FOR(i, 0, 4) {
					int nx = now.x + "1102"[i] - '1';
					int ny = now.y + "0211"[i] - '1';
					if (out(nx, ny)) continue;
					if (m[nx][ny] == 0) continue;
					if (board[nx][ny][now.color]) continue;
					int tmp = board[nx][ny][!now.color];
					if (tmp && tmp < round) continue;
					board[nx][ny][now.color] = round;
					q.push({ nx,ny,now.color });
				}
			}
		}

		// count
		int cnt = 0;
		FOR(i, 0, N) {
			FOR(j, 0, M) {
				if (board[i][j][0] + board[i][j][1] == 0) continue;
				if (board[i][j][0] == board[i][j][1]) {
					cnt++;
				}
			}
		}
		res = max(res, cnt);

	} while (next_permutation(all(v)));

	cout << res;

}
