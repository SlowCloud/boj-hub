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


int board[33][33];

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int sx, sy;
	sx = sy = 15;

	FOR(i, 0, 15) {
		board[i][sy] = 1;
		board[sx][i] = 16;
		board[sx + 1 + i][sy] = 256;
		board[sx][sy + 1 + i] = 256*15;
	}

	FOR(i, 0, 30) {
		FOR(j, 0, 30) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}

}
