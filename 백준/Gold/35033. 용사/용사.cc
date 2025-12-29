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

#define FOR_(type,i, a, b) for(type i=a;i<b;i++)
#define FOR(i,a,b) FOR_(int,i,a,b)
#define FORLL(i,a,b) FOR_(ll,i,a,b)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'




int dep[222'222];
int vst[222'222];

vector<int> G[222'222];

void dfs_dep(int now, int prev) {
	if(now != 1) dep[now] += G[now].size() > 2;
	for (int next : G[now]) {
		if (next == prev) continue;
		dfs_dep(next, now);
		dep[now] += dep[next];
	}
}

vector<int> res;
void dfs(int now, int prev) {
	vst[now] = 1;
	for (int next : G[now]) {
		if (next == prev) continue;
		dfs(next, now);
	}
	res.push_back(now);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	FOR(i,1,N) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	dfs_dep(1, -1);
	for (auto& g : G) {
		sort(all(g), [&](int a, int b) {
			return dep[a] > dep[b];
		});
	}
	dfs(1, -1);

	for (const auto& v : res) {
		cout << v << ' ';
	}

}

