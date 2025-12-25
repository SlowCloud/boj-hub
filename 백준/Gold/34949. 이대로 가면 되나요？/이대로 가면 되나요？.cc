#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


vector<int> G[222'222];
int vst[222'222];
int d[222'222];

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int N; cin >> N;
	FOR(i, 1, N + 1) {
		int n; cin >> n;
		G[n].push_back(i);
	}

	queue<int> q; q.push(N);
	vst[N] = 1;
	memset(d, -1, sizeof d);
	d[N] = 0;
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int next : G[now]) {
			if (vst[next]) continue;
			vst[next] = 1;
			d[next] = d[now] + 1;
			q.push(next);
		}
	}

	FOR(i, 1, N + 1) cout << d[i] << endl;

}
