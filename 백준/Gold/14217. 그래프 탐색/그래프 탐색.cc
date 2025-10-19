#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


set<int> G[555];
int vst[555];

int N, M;

void bfs() {

	memset(vst, -1, sizeof vst);
	vst[1] = 0;
	queue<int> q; q.push(1);

	while (q.size()) {
		for (int _ = q.size(); _--;) {
			int now = q.front(); q.pop();
			for(const int& next : G[now]) {
				if (vst[next] != -1) continue;
				vst[next] = vst[now] + 1;
				q.push(next);
			}
		}
	}

	FOR(i, 1, N + 1) cout << vst[i] << ' '; cout << endl;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;

	FOR(_, 0, M) {
		int a, b; cin >> a >> b;
		G[a].insert(b);
		G[b].insert(a);
	}

	int q; cin >> q;
	FOR(_, 0, q) {
		int a, i, j; cin >> a >> i >> j;
		if (a == 2) {
			G[i].erase(j);
			G[j].erase(i);
		}
		else {
			G[i].insert(j);
			G[j].insert(i);
		}
		bfs();
	}

}
