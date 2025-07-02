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

// https://www.acmicpc.net/problem/5911


int board[3][3];
int vst[3][3];
int N;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> board[i][j];
		}
	}

	queue<pii> q;
	q.push({ 0,0 });
	vst[0][0] = 1;

	auto out = [&](int a, int b) -> bool {
		return min(a, b) < 0 || max(a, b) >= N;
	};

	while (q.size()) {
		auto [x, y] = q.front(); q.pop();

		FOR(i, 0, 2) {
			int nx = x + ("12"[i] - '1') * board[x][y];
			int ny = y + ("21"[i] - '1') * board[x][y];
			if (out(nx, ny)) continue;
			if (vst[nx][ny]) continue;
			vst[nx][ny] = 1;
			if (board[nx][ny] != -1) {
				q.push({ nx,ny });
			}
		}
	}

	if (vst[N - 1][N - 1]) {
		cout << "HaruHaru";
	}
	else {
		cout << "Hing";
	}

}
