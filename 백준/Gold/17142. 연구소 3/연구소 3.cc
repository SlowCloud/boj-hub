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


int board[111][111];
int vst[111][111];

vector<pii> viruses;

int N;
int empty_;

inline bool out(const int& x, const int& y) {
	return min(x, y) < 0 || max(x, y) >= N;
}

int bfs(const vector<int>& selected) {

	memset(vst, 0, sizeof vst);

	queue<pii> q;
	for (const int& idx : selected) {
		q.push(viruses.at(idx));
	}

	int res = -1;
	int filled = 0;
	while (q.size()) {
		res++;
		if (filled == empty_) break;
		for (int t = q.size(); t--;) {
			const auto [x, y] = q.front(); q.pop();
			FOR(i, 0, 4) {
				const int nx = x + "1102"[i] - '1';
				const int ny = y + "0211"[i] - '1';
				if (out(nx, ny)) continue;
				if (board[nx][ny] == 1) continue;
				if (vst[nx][ny]) continue;
				vst[nx][ny] = 1;
				filled += board[nx][ny] == 0;
				q.push({ nx,ny });
			}
		}
	}

	return filled == empty_ ? res : 1e9;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	int M; cin >> M;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				viruses.push_back({ i,j });
			}
			empty_ += board[i][j] == 0;
		}
	}

	vector<int> selector(viruses.size() - M);
	selector.resize(viruses.size(), 1);

	int res = 1e9;
	do {
		vector<int> selected;
		FOR(i, 0, selector.size()) {
			if (selector[i]) selected.push_back(i);
		}
		res = min(res, bfs(selected));
	} while (next_permutation(all(selector)));

	cout << (res == 1e9 ? -1 : res);

}
