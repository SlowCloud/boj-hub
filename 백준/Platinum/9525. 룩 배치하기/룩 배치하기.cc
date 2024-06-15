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


int N, M;

int board[111][111];

int l[111][111], r[111][111];

bool out(int x, int y) {
	return min(x, y) < 0 || max(x, y) >= N;
}

void buildl() {
	int now = 0;
	For(i, 0, N) {
		For(j, 0, N) {
			if (board[i][j]) {
				now++; continue;
			}
			l[i][j] = now;
		}
		now++;
	}
}

void buildr() {
	int now = 0;
	For(j, 0, N) {
		For(i, 0, N) {
			if (board[i][j]) {
				now++; continue;
			}
			r[i][j] = now;
		}
		now++;
	}
}

vector<int> G[111'111];

int vst[111'111];
int p[111'111];

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

	cin >> N;

	For(i, 0, N) For(j, 0, N) {
		char c; cin >> c;
		board[i][j] = c == 'X';
	}

	buildl();
	buildr();

	For(i, 0, N) For(j, 0, N) {
		if (board[i][j]) continue;
		G[l[i][j]].push_back(r[i][j]);
	}

	memset(p, -1, sizeof p);

	int res = 0;
	For(i, 0, N * N + 1) {
		memset(vst, 0, sizeof vst);
		res += dfs(i);
	}
	
	cout << res;

}