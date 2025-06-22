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


constexpr int R = 5, C = 7;

char board[55][R][C];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 0, N) {
		FOR(j, 0, R) {
			FOR(k, 0, C) {
				cin >> board[i][j][k];
			}
		}
	}

	int gap = 1e9;
	int l, r;
	l = r = -1;
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			int cnt = 0;
			FOR(a, 0, R) {
				FOR(b, 0, C) {
					cnt += board[i][a][b] != board[j][a][b];
				}
			}
			if (gap > cnt) {
				gap = cnt;
				l = i; r = j;
			}
		}
	}

	cout << l + 1 << ' ' << r + 1;

}
