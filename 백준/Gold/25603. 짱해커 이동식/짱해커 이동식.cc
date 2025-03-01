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


int board[111'111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K; cin >> N >> K;
	FOR(i, 0, N) cin >> board[i];

	int l, r, m;
	l = 1; r = 1e9;

	while (l <= r) {
		m = l + r >> 1;

		bool possible = true;
		int gap = 0;
		FOR(i, 0, N) {
			if (board[i] <= m) {
				gap = 0;
			}
			else {
				gap++;
			}
			if (gap >= K) {
				possible = false; break;
			}
		}
		if (possible) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}

	cout << l;

}
