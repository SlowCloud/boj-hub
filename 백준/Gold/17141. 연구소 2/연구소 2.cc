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


int N, M;

int board[55][55];
int vst[55][55];

inline bool out(const int x, const int y) {
	return min(x, y) < 0 || max(x, y) >= N;
}

int bfs(const vector<pii>& pos) {
	memset(vst, 0, sizeof vst);
	queue<pii> q;
	for (const auto& [sx,sy] : pos) {
		q.push({ sx,sy });
		vst[sx][sy] = 1;
	}

	int cnt = 0;
	while (q.size()) {
		cnt++;
		for (int t = q.size(); t--;) {
			const auto [x, y] = q.front(); q.pop();
			FOR(i, 0, 4) {
				int nx = x + "1102"[i] - '1';
				int ny = y + "0211"[i] - '1';
				if (out(nx, ny)) continue;
				if (board[nx][ny] == 1) continue;
				if (vst[nx][ny]) continue;
				vst[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}

	FOR(i, 0, N) FOR(j, 0, N) {
		if (board[i][j] != 1 && vst[i][j] == 0) return 1e9;
	}
	return cnt - 1;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;

	vector<pii> v;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			int n; cin >> n;
			board[i][j] = n;
			if (n == 2) {
				v.push_back({ i,j });
			}
		}
	}

	int res = 1e9;
	vector<int> tmp(M, 1);
	tmp.resize(v.size());
	sort(all(tmp));
	do {
		vector<pii> pos;
		FOR(i, 0, tmp.size()) {
			if (tmp[i]) pos.push_back(v[i]);
		}
		res = min(res, bfs(pos));
	} while (next_permutation(all(tmp)));

	cout << (res == 1e9 ? -1 : res);

}
