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

int vst[22][22];

bool out(int x, int y, int N) {
	return min(x, y) < 0 || max(x, y) >= N;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;

	For(t, 1, T + 1) {
		For(i, 0, 22) For(j, 0, 22) vst[i][j] = 1e9;
		int N; cin >> N;
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--; c1--; r2--; c2--;
		vst[r1][c1] = 0;
		queue<ii> q; q.push({ r1,c1 });
		while (q.size()) {
			ii now = q.front(); q.pop();
			For(i, 0, 8) {
				int nx = now.first + "01344310"[i] - '2';
				int ny = now.second + "34431001"[i] - '2';
				if (out(nx, ny, N)) continue;
				if (vst[nx][ny] <= vst[now.first][now.second] + 1) continue;
				vst[nx][ny] = vst[now.first][now.second] + 1;
				q.push({ nx,ny });
			}
		}
		cout << "Case #" << t << ": ";
		cout << vst[r2][c2] << endl << endl;
	}

}