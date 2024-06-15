#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack>
#include <unordered_map>
#include <map>
#include <numeric>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;

#define FOR(i,a,b) For(i,a,b)
#define FOr(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'


int R, C, N;

int board[333][333];

int l[333][333], r[333][333];

bool out(int x, int y) {
	return min(x, y) < 0 || max(x, y) >= N;
}

int LL, RR;

void buildl() {
	LL = 0;
	For(i, 0, R) {
		For(j, 0, C) {
			l[i][j] = LL;
		}
		LL++;
	}
}

void buildr() {
	RR = 0;
	For(j, 0, C) {
		For(i, 0, R) {
			r[i][j] = RR;
		}
		RR++;
	}
}

vector<int> G[333];

int vst[333];
int p[333];

int dfs(int now) {
	if (vst[now]) return false;
	vst[now] = 1;
	for (int next : G[now]) {
		if (p[next] == -1 || dfs(p[next])) {
			p[next] = now; return true;
		}
	}
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> C >> N;

	For(i, 0, N) {
		int a, b; cin >> a >> b;
		a--; b--;
		board[a][b] = 1;
	}

	buildl();
	buildr();

	For(i, 0, R) For(j, 0, C) {
		if (board[i][j]) continue;
		G[l[i][j]].push_back(r[i][j]);
	}

	memset(p, -1, sizeof p);

	int res = 0;
	For(i, 0, LL) {
		memset(vst, 0, sizeof vst);
		res += dfs(i);
	}
	
	cout << res;

}