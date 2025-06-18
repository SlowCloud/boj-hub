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

int board[111][111];
int R, C;

void sort_row() {
	int next_col_size = -1;
	FOR(i, 0, R) {
		vector<int> v;
		FOR(j, 0, C) {
			int now = board[i][j];
			if (now == 0) continue;
			v.push_back(now);
		}

		map<int, int> cnt;
		for (auto& i : v) {
			cnt[i]++;
		}

		vector<pii> w;
		for (auto& p : cnt) {
			w.push_back({ p.second, p.first });
		}
		sort(all(w)); // count, number pair

		vector<int> row;
		for (auto& p : w) {
			row.push_back(p.second);
			row.push_back(p.first);
		}
		if (row.size() > 100) row.resize(100);
		
		FOR(j, 0, row.size()) {
			board[i][j] = row[j];
		}
		FOR(j, row.size(), 100) {
			board[i][j] = 0;
		}

		next_col_size = max(next_col_size, (int) row.size());
	}
	C = next_col_size;
}

void sort_col() {
	int next_row_size = -1;
	FOR(i, 0, C) {
		vector<int> v;
		FOR(j, 0, R) {
			int now = board[j][i];
			if (now == 0) continue;
			v.push_back(now);
		}

		map<int, int> cnt;
		for (auto& i : v) {
			cnt[i]++;
		}

		vector<pii> w;
		for (auto& p : cnt) {
			w.push_back({ p.second, p.first });
		}
		sort(all(w)); // count, number pair

		vector<int> col;
		for (auto& p : w) {
			col.push_back(p.second);
			col.push_back(p.first);
		}
		if (col.size() > 100) col.resize(100);

		FOR(j, 0, col.size()) {
			board[j][i] = col[j];
		}
		FOR(j, col.size(), 100) {
			board[j][i] = 0;
		}

		next_row_size = max(next_row_size, (int) col.size());
	}
	R = next_row_size;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int r, c, k; cin >> r >> c >> k;
	r--; c--;
	R = C = 3;

	FOR(i, 0, R) {
		FOR(j,0,C) {
			cin >> board[i][j];
		}
	}

	int res = 0;
	while (board[r][c] != k && res <= 100) {
		res++;
		if (R >= C) {
			sort_row();
		}
		else {
			sort_col();
		}
	}

	if (res > 100) res = -1;

	cout << res;

}
