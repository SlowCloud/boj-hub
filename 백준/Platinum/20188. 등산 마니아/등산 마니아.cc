#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using pii = pair<int, int>;


vector<int> G[300'001];

int N;

long long cnt[300'001];

void dfs(int now, int prev) {

	cnt[now] = 1;
	for (int next : G[now]) {
		if (next == prev) continue;
		dfs(next, now);
		cnt[now] += cnt[next];
	}

}

int main() {

	cin >> N;

	For(i, 1, N) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	dfs(1, -1);

	long long res = 0;

	For(i, 2, N + 1) {
		res += cnt[i] * (cnt[i] - 1) / 2;
		res += cnt[i] * (N - cnt[i]);
	}

	cout << res;

}