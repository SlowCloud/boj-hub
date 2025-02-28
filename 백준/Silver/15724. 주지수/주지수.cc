#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
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


ll board[1111][1111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	FOR(i, 1, N + 1) {
		FOR(j, 1, M + 1) {
			cin >> board[i][j];
			board[i][j] += board[i][j - 1];
		}
		FOR(j, 1, M + 1) {
			board[i][j] += board[i - 1][j];
		}
	}

	int K; cin >> K;
	while (K--) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << board[c][d] - board[a - 1][d] - board[c][b - 1] + board[a - 1][b - 1] << endl;
	}


}
