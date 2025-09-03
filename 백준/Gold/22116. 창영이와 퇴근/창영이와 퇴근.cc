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


int board[1111][1111];
int vst[1111][1111];

int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	int N; cin >> N;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> board[i][j];
		}
	}

#define out(x,y) (min(x,y) < 0 || max(x,y) >= N)

	int l = 0, r = 1e9, m;
	while (l <= r) {
		m = l + r >> 1;
		queue<pii> q; q.push({ 0,0 });
		memset(vst, 0, sizeof vst);
		vst[0][0] = 1;

		while (q.size()) {
			const auto [x, y] = q.front(); q.pop();
			FOR(i, 0, 4) {
				const int nx = x + "1102"[i] - '1';
				const int ny = y + "0211"[i] - '1';
				if (out(nx, ny)) continue;
				if (vst[nx][ny]) continue;
				if (abs(board[nx][ny] - board[x][y]) > m) continue;
				vst[nx][ny] = 1;
				q.push({ nx,ny });
			}
			if (vst[N - 1][N - 1]) break;
		}

		if (vst[N - 1][N - 1]) r = m - 1;
		else l = m + 1;
	}

	cout << l;

}
