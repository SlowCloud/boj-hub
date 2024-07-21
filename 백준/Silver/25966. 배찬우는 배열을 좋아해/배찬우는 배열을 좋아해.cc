#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int board[3333][3333];
int row[3333];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	iota(row, row + 3333, 0);

	int N, M, Q; cin >> N >> M >> Q;

	For(i, 0, N) For(j, 0, M) {
		cin >> board[i][j];
	}

	while (Q--) {
		int op; cin >> op;
		if (op == 0) {
			int a, b, c; cin >> a >> b >> c;
			board[row[a]][b] = c;
		}
		else {
			int a, b; cin >> a >> b;
			swap(row[a], row[b]);
		}
	}

	For(i, 0, N) {
		For(j, 0, M) {
			cout << board[row[i]][j] << ' ';
		}
		cout << endl;
	}
}