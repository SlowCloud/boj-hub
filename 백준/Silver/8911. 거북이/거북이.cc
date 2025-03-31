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



int main() {
	cin.tie(0)->sync_with_stdio(0);


	int T; cin >> T;
	while (T--) {
		int lx, rx, ly, ry;

		lx = rx = ly = ry = 0;

		int x, y;
		x = y = 0;
		int d = 0;

		string s; cin >> s;
		for (char c : s) {
			if (c == 'F') {
				x += "0121"[d] - '1';
				y += "1210"[d] - '1';
				lx = min(lx, x); rx = max(rx, x);
				ly = min(ly, y); ry = max(ry, y);
			}
			else if (c == 'B') {
				x -= "0121"[d] - '1';
				y -= "1210"[d] - '1';
				lx = min(lx, x); rx = max(rx, x);
				ly = min(ly, y); ry = max(ry, y);
			}
			else if (c == 'L') {
				d = (d + 3) % 4;
			}
			else { // 'R'
				d = (d + 1) % 4;
			}
		}

		cout << abs(lx - rx) * abs(ly - ry) << endl;
	}

}

