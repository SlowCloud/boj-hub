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

int m[55][55];
int board[55][55];
int N, M, K;

void doRotate(const int R, const int C, const int layer) {
	int r, c;
	r = R; c = C;
	r -= layer;
	c -= layer;
	const int CNT = layer * 2 + 1;
	deque<int> dq;
	FOR(i, 0, 4) {
		FOR(j, 1, CNT) {
			dq.push_back(board[r][c]);
			r += "1210"[i] - '1';
			c += "2101"[i] - '1';
		}
	}
	dq.push_front(dq.back()); dq.pop_back();
	FOR(i, 0, 4) {
		FOR(j, 1, CNT) {
			board[r][c] = dq.front(); dq.pop_front();
			r += "1210"[i] - '1';
			c += "2101"[i] - '1';
		}
	}
}

void check() {
	FOR(i, 0, N) {
		FOR(j, 0, M) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

void rotate(const int r, const int c, const int s) {
	FOR(i, 1, s + 1) {
		doRotate(r, c, i);
	}
	// check();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;

	FOR(i, 0, N) {
		FOR(j, 0, M) {
			cin >> m[i][j];
		}
	}

	vector<tuple<int, int, int>> op;
	while (K--) {
		int a, b, c; cin >> a >> b >> c;
		op.push_back({ a - 1,b - 1,c });
	}

	int res = 1e9;
	sort(all(op));
	do {
		memcpy(board, m, sizeof m);

		for (auto& i : op) {
			auto [a, b, c] = i;
			rotate(a, b, c);
		}

		FOR(i, 0, N) {
			int now = 0;
			FOR(j, 0, M) {
				now += board[i][j];
			}
			res = min(res, now);
		}

	} while (next_permutation(all(op)));

	cout << res;


}
