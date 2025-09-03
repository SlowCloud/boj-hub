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
			vst[i][j] = 2e9;
		}
	}

#define out(x,y) (min(x,y) < 0 || max(x,y) >= N)

	priority_queue<tuple<int, int, int>> q; q.push({ 0,0,0 });
	vst[0][0] = 0;

	while (q.size()) {
		const auto [_, x, y] = q.top(); q.pop();
		FOR(i, 0, 4) {
			const int nx = x + "1102"[i] - '1';
			const int ny = y + "0211"[i] - '1';
			if (out(nx, ny)) continue;
			const int tmp = max(vst[x][y], abs(board[nx][ny] - board[x][y]));
			if (tmp >= vst[nx][ny]) continue;
			vst[nx][ny] = tmp;
			q.push({ -tmp,nx,ny });
		}
	}

	cout << vst[N - 1][N - 1];

}
