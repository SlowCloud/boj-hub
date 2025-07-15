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


char board[11][11];
int R, C;

int vst[11][11][11][11];

struct Ball {
	int x, y;
	bool operator == (const Ball& b) const {
		return x == b.x && y == b.y;
	}
	void left() {
		y--;
	}
	void right() {
		y++;
	}
	void up() {
		x--;
	}
	void down() {
		x++;
	}
	bool exit() {
		return board[x][y] == 'O';
	}
	bool wall() {
		return board[x][y] == '#';
	}
};

// returns next position of red & blue
pair<Ball, Ball> move(Ball red, Ball blue, int d) {

	Ball next_red = red, next_blue = blue;

	// left
	if (d == 0) {
		if (red.y > blue.y) swap(next_red, next_blue);
		while (1) {
			next_red.left();
			if (next_red.exit()) break;
			if (next_red.wall()) {
				next_red.right(); break;
			}
		}
		while (1) {
			next_blue.left();
			if (next_blue.exit()) break;
			if (next_blue.wall() || next_red == next_blue) {
				next_blue.right(); break;
			}
		}
		if (red.y > blue.y) swap(next_red, next_blue);
		return { next_red, next_blue };
	}

	// right
	if (d == 1) {
		if (red.y < blue.y) swap(next_red, next_blue);
		while (1) {
			next_red.right();
			if (next_red.exit()) break;
			if (next_red.wall()) {
				next_red.left(); break;
			}
		}
		while (1) {
			next_blue.right();
			if (next_blue.exit()) break;
			if (next_blue.wall() || next_red == next_blue) {
				next_blue.left(); break;
			}
		}
		if (red.y < blue.y) swap(next_red, next_blue);
		return { next_red, next_blue };
	}

	// down
	if (d == 2) {
		if (red.x < blue.x) swap(next_red, next_blue);
		while (1) {
			next_red.down();
			if (next_red.exit()) break;
			if (next_red.wall()) {
				next_red.up(); break;
			}
		}
		while (1) {
			next_blue.down();
			if (next_blue.exit()) break;
			if (next_blue.wall() || next_red == next_blue) {
				next_blue.up(); break;
			}
		}
		if (red.x < blue.x) swap(next_red, next_blue);
		return { next_red, next_blue };
	}

	// up
	if (d == 3) {
		if (red.x > blue.x) swap(next_red, next_blue);
		while (1) {
			next_red.up();
			if (next_red.exit()) break;
			if (next_red.wall()) {
				next_red.down(); break;
			}
		}
		while (1) {
			next_blue.up();
			if (next_blue.exit()) break;
			if (next_blue.wall() || next_red == next_blue) {
				next_blue.down(); break;
			}
		}
		if (red.x > blue.x) swap(next_red, next_blue);
		return { next_red, next_blue };
	}
	
}

int dfs(const Ball& red, const Ball& blue, int depth) {
	int& vst_now = vst[red.x][red.y][blue.x][blue.y];
	if (vst_now <= depth) return 1e9;
	vst_now = depth;
	int res = 1e9;
	FOR(i, 0, 4) {
		auto [next_red, next_blue] = move(red, blue, i);
		if (next_blue.exit()) continue;
		if (next_red.exit())
 			return depth;
		res = min(res, dfs(next_red, next_blue, depth + 1));
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> C;
	Ball red, blue;
	FOR(i, 0, R) {
		FOR(j, 0, C) {
			cin >> board[i][j];
			if (board[i][j] == 'B') {
				blue.x = i; blue.y = j;
				board[i][j] = '.';
			}
			if (board[i][j] == 'R') {
				red.x = i; red.y = j;
				board[i][j] = '.';
			}
		}
	}
	
	FOR(a, 0, 10) FOR(b, 0, 10) FOR(c, 0, 10) FOR(d, 0, 10)
		vst[a][b][c][d] = 1e9;

	int res = dfs(red, blue, 1);
	if (res == 1e9) res = -1;
	cout << res;

}
