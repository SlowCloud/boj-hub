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


int vst[333][333];
char board[333][333];
int R, C;

inline bool out(const int x, const int y) {
	return min(x, y) < 0 || x >= R || y >= C;
}

pii bfs(const int x, const int y) {

	vst[x][y] = 1;

	int sheep = board[x][y] == 'o';
	int wolf = board[x][y] == 'v';

	queue<pii> q; q.push({ x,y });
	while (q.size()) {
		auto [x, y] = q.front(); q.pop();
		FOR(i, 0, 4) {
			int nx = x + "1102"[i] - '1';
			int ny = y + "0211"[i] - '1';
			if (out(nx, ny)) continue;
			if (vst[nx][ny]) continue;
			if (board[nx][ny] == '#') continue;
			vst[nx][ny] = 1;
			sheep += board[nx][ny] == 'o';
			wolf += board[nx][ny] == 'v';
			q.push({ nx,ny });
		}
	}

	if (sheep > wolf) {
		return { sheep, 0 };
	}
	else {
		return { 0, wolf };
	}

}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> C;

	FOR(i, 0, R) {
		FOR(j, 0, C) {
			cin >> board[i][j];
		}
	}

	int a, b;
	a = b = 0;
	FOR(i, 0, R) {
		FOR(j, 0, C) {
			if (!vst[i][j] && board[i][j] != '#') {
				auto [u, v] = bfs(i, j);
				a += u;
				b += v;
			}
		}
	}
	cout << a << ' ' << b;

}
