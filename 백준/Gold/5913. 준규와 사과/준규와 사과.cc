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


int vst[5][5];
int K;

bool out(int x, int y) {
	return min(x, y) < 0 || 5 <= max(x, y);
}

int dfs(int x, int y, int cnt) {
	if (x == 4 && y == 4) {
		return cnt == 25 - K;
	}
	int res = 0;
	vst[x][y] = 1;
	FOR(i, 0, 4) {
		int nx = x + "1102"[i] - '1';
		int ny = y + "0211"[i] - '1';
		if (out(nx, ny)) continue;
		if (vst[nx][ny]) continue;
		res += dfs(nx, ny, cnt + 1);
	}
	vst[x][y] = 0;
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> K;
	FOR(i, 0, K) {
		int a, b; cin >> a >> b;
		vst[a - 1][b - 1] = 1;
	}

	cout << dfs(0, 0, 1);

}
