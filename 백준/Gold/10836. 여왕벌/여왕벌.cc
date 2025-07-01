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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int M, N; cin >> M >> N;

	vector<int> v(M * 2 - 1);
	v[0] = 1;

	FOR(i, 0, N) {
		int a, b, c; cin >> a >> b >> c;
		int idx = 0;

		idx += a;
		if (idx >= v.size()) continue;
		v[idx] += 1;

		idx += b;
		if (idx >= v.size()) continue;
		v[idx] += 1;
	}

	FOR(i, 1, v.size()) {
		v[i] += v[i - 1];
	}

	// for (auto& i : v) cout << i << ' ';

	FOR(i, 0, M) {
		board[M - i - 1][0] = v[i];
	}

	FOR(i, M, v.size()) {
		board[0][i - M + 1] = v[i];
	}

	FOR(i, 1, M) {
		FOR(j, 1, M) {
			board[i][j] = max(board[i - 1][j], board[i][j - 1]);
		}
	}

	FOR(i, 0, M) {
		FOR(j, 0, M) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}

}
