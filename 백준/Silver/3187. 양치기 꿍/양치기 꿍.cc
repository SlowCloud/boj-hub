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


int board[333][333];
int vst[333][333];
int R, C;
int sheep = 0, wolf = 0;

bool out(int x, int y) {
	return min(x, y) < 0 || x >= R || y >= C;
}

void bfs(int sx, int sy) {
	queue<pii> q;
	q.push({ sx,sy });

	int s, w;
	s = w = 0;

	if (board[sx][sy] == 1) {
		s++;
	}
	if (board[sx][sy] == 2) {
		w++;
	}

	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		FOR(i, 0, 4) {
			int nx = x + "1102"[i] - '1';
			int ny = y + "0211"[i] - '1';
			if (out(nx, ny)) continue;
			if (vst[nx][ny]) continue;
			vst[nx][ny] = 1;
			if (board[nx][ny] == 1) s++;
			if (board[nx][ny] == 2) w++;
			q.push({ nx,ny });
		}
	}

	if (s > w) sheep += s;
	else wolf += w;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	
	cin >> R >> C;

	vector<pii> sheeps;
	vector<pii> wolves;

	FOR(i, 0, R) {
		FOR(j, 0, C) {
			char c; cin >> c;
			if (c == 'k') {
				board[i][j] = 1;
			}
			if (c == 'v') {
				board[i][j] = 2;
			}
			if (c == '#') {
				board[i][j] = 3;
				vst[i][j] = 1;
			}
		}
	}
	
	FOR(i, 0, R) {
		FOR(j,0,C) {
			if (vst[i][j]) continue;
			vst[i][j] = 1;
			bfs(i, j);
		}
	}

	cout << sheep << ' ' << wolf;


}

