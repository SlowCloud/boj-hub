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


int board[777][777];

void prepare_board(const int M) {
	FOR(i, 0, M) {
		board[i][0] = board[0][i] = 1;
	}
}

vector<int> build_grow(const vector<int>& v) {
	vector<int> res;
	FOR(i, 0, v[0]) {
		res.push_back(0);
	}
	FOR(i, 0, v[1]) {
		res.push_back(1);
	}
	FOR(i, 0, v[2]) {
		res.push_back(2);
	}
	return res;
}

void build_board(const int M, const vector<int>& total) {

	FOR(i, 0, M) {
		board[M - i - 1][0] += total[i];
	}

	FOR(i, M, M * 2 - 1) {
		board[0][i - M + 1] += total[i];
	}

	FOR(i, 1, M) {
		FOR(j, 1, M) {
			int now = max({ board[i - 1][j], board[i][j - 1], board[i - 1][j - 1] });
			board[i][j] = now;
		}
	}
}

void print_board(const int M) {
	FOR(i, 0, M) {
		FOR(j, 0, M) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int M, N; cin >> M >> N;

	prepare_board(M);

	vector<int> total(M * 2 - 1);
	FOR(i, 0, N) {
		vector<int> v(3);
		for (auto& i : v) cin >> i;
		vector<int> w = build_grow(v);
		FOR(i, 0, w.size()) {
			total[i] += w[i];
		}
	}

	build_board(M, total);
	print_board(M);

}
