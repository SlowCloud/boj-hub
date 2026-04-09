// #include <bits/stdc++.h>

#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(auto i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using ll = long long;
using pii = pair<int, int>;

int board[111][111];
int vst[111][111];

void solve() {
	
	memset(board, 0, sizeof board);
	memset(vst,0,sizeof vst);

	int H,W,O,F;
	cin >>H>>W>>O>>F;

	int sx, sy, ex, ey;
	cin >> sx>>sy>>ex>>ey;

	FOR(i,0,O) {
		int x,y,l; cin >>x>>y>>l;
		board[x][y] = l;
	}

	queue<pii> q; q.push({sx,sy});
	vst[sx][sy] = F;

	const auto out = [&](const int x, const int y) -> bool {
		return min(x,y) < 1 || x > H || y > W;
	};

	while(q.size()) {
		const auto [x,y] = q.front(); q.pop();
		if(vst[x][y] == 0) continue;
		FOR(i,0,4) {
			const int nx = x+ "1102"[i] - '1';
			const int ny = y+ "0211"[i] - '1';
			if(out(nx,ny) || vst[nx][ny]) continue;
			if(board[nx][ny] - board[x][y] > vst[x][y]) continue;
			vst[nx][ny] = vst[x][y] - 1;
			if(nx == ex && ny == ey) {
				cout << "잘했어!!" << endl; return;
			}
			q.push({nx,ny});
		}
	}
	cout << "인성 문제있어??" << endl;

}


int main() {
	std::cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while(T--) {
		solve();
	}

	return 0;
}
