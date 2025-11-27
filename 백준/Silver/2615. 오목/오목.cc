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


int board[22][22];

bool out(int x, int y) {
	return min(x, y) < 0 || max(x, y) >= 19;
}

int check_line(int x, int y, pii dir) {
	int now = board[x][y];
	if (now == 0) return 0;

	// 이전 칸에 동일한 돌이 있는지 확인. 있으면 건너뜀
	x -= dir.first; y -= dir.second;
	if (!out(x, y) && board[x][y] == now) return 0;
	x += dir.first; y += dir.second;

	FOR(i, 0, 4) {
		x += dir.first; y += dir.second;
		if (out(x, y)) return 0;
		if (board[x][y] != now) return 0;
	}

	// 6목 처리
	x += dir.first; y += dir.second;
	if (!out(x, y) && board[x][y] == now) return 0;
	
	return now;
}

int check_every_line(int x, int y) {
	for (const auto& p : vector<pii>{ {1,0}, {1,1}, {0,1}, {-1,1} }) {
		if (int res = check_line(x, y, p); res != 0) return res;
	}
	return 0;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	FOR(i, 0, 19) FOR(j, 0, 19) cin >> board[i][j];

	FOR(i, 0, 19) FOR(j, 0, 19) {
		if (int now = check_every_line(i, j); now != 0) {
			cout << now << endl;
			cout << i + 1 << ' ' << j + 1 << endl;
			exit(0);
		}
	}
	cout << 0;

}
