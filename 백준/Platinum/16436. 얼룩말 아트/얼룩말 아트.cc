#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int board[3333][3333];
int diamond[3333][3333];

void draw_diamond(int a, int b, int c) {
	if (c < 0) return;
	diamond[a - c][b] += 1;
	diamond[a + 1][b - c - 1] -= 1;
	diamond[a + 1][b + c + 1] -= 1;
	diamond[a + c + 2][b] += 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int R, C, K; cin >> R >> C >> K;

	while (K--) {
		int op; cin >> op;
		if (op == 1) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			a++; b++; c++; d++;
			board[a][b] += 1; board[a][d + 1] -= 1;
			board[c + 1][b] -= 1; board[c + 1][d + 1] += 1;
		}
		else {
			int a, b, c; cin >> a >> b >> c;
			a++; b++;
			draw_diamond(a, b, c);
			draw_diamond(a, b, c - 1);
		}
	}

	FOR(i, 1, R + 1) {
		FOR(j, 1, C + 1) {
			board[i][j] += board[i][j - 1];
		}
	}
	FOR(j, 1, C + 1) {
		FOR(i, 1, R + 1) {
			board[i][j] += board[i - 1][j];
		}
	}

	auto out = [&](int a, int b) -> bool {
		return min(a, b) < 1 || a > R || b > C;
	};

	// top right to bottom left
	FOR(j, 1, R + C + 1) {
		int x = 1;
		int y = j;
		while (1) {
			if (!out(x, y) && y >= 1) {
				diamond[x][y] += diamond[x - 1][y + 1];
			}
			x++; y--;
			if (y < 0) break;
		}
	}
	// top left to bottom right
	FOR(j, 1, R + C + 1) {
		int x = 1;
		int y = j - R;
		while (1) {
			if (!out(x, y) && y > 1) {
				diamond[x][y] += diamond[x - 1][y - 1];
			}
			x++; y++;
			if (y > C) break;
		}
	}

	FOR(j, 1, C + 1) {
		FOR(i, 1, R + 1) {
			int now = board[i][j] + diamond[i][j];
			cout << (now % 2 ? '#' : '.');
		}
		cout << endl;
	}

}

