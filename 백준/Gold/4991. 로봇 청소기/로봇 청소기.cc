#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int R, C;
inline bool out(const int x, const int y) {
	return min(x, y) < 0 || x >= R || y >= C;
}

int board[22][22];
int vst[22][22];
int calc(const pii& s, const pii& e) {

	memset(vst, 0, sizeof vst);
	queue<pii> q; q.push(s);
	int dist = 0;
	while (q.size()) {
		dist++;
		for (int t = q.size(); t--;) {
			const auto [x, y] = q.front(); q.pop();
			FOR(i, 0, 4) {
				const int nx = x + "1102"[i] - '1';
				const int ny = y + "0211"[i] - '1';
				if (out(nx, ny)) continue;
				if (vst[nx][ny]) continue;
				if (board[nx][ny]) continue;
				vst[nx][ny] = 1;
				pii p = { nx,ny };
				if (p == e) {
					return dist;
				}
				q.push({ nx,ny });
			}
		}
	}
	return 1e9;

}

int dist[22][22][22][22];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	
	while (1) {
		begin:

		memset(vst, 0, sizeof vst);
		memset(board, 0, sizeof board);

		cin >> C >> R;
		if (R + C == 0) break;

		pii s;
		vector<pii> v;

		FOR(i, 0, R) {
			FOR(j, 0, C) {
				char c; cin >> c;
				if (c == 'o') {
					s = { i,j };
				}
				if (c == '*') {
					v.push_back({ i,j });
				}
				if (c == 'x') {
					board[i][j] = 1;
				}
			}
		}

		for(const auto& p : v) {
			int tmp = calc(s, p);
			dist[s.first][s.second][p.first][p.second] =
				dist[p.first][p.second][s.first][s.second] = tmp;
			if (tmp == 1e9) {
				cout << -1 << endl;
				goto begin;
			}
		}
		FOR(i, 0, v.size()) {
			FOR(j, i + 1, v.size()) {
				const auto& a = v[i], & b = v[j];
				dist[a.first][a.second][b.first][b.second] =
					dist[b.first][b.second][a.first][a.second] = calc(a, b);
			}
		}

		sort(all(v));
		int res = 1e9;
		do {
			auto now = s;
			int d = 0;
			for (const auto& p : v) {
				const auto& tmp = dist[now.first][now.second][p.first][p.second];
				if (tmp == 1e9) {
					d = 1e9; break;
				}
				d += tmp;
				now = p;
			}
			res = min(res, d);
		} while (next_permutation(all(v)));

		cout << (res == 1e9 ? -1 : res) << endl;

	}


}
