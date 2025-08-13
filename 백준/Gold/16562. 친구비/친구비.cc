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


int vst[11'111];
int A[11'111];

vector<int> G[11'111];

int bfs(int s) {
	queue<int> q; q.push(s);
	vst[s] = 1;
	int res = A[s];

	while (q.size()) {
		int now = q.front(); q.pop();
		for (const int& next : G[now]) {
			if (vst[next]) continue;
			vst[next] = 1;
			res = min(res, A[next]);
			q.push(next);
		}
	}

	return res;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int N, M, K;
	cin >> N >> M >> K;

	FOR(i, 0, N) {
		cin >> A[i];
	}

	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int res = 0;
	FOR(i, 0, N) {
		if (!vst[i]) {
			res += bfs(i);
		}
	}

	if (res <= K) {
		cout << res;
	}
	else {
		cout << "Oh no";
	}

}
