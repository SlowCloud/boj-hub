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

vector<int> G[222'222];
int vst[222'222];
int cnt[222'222];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	FOR(i, 0, M) {
		int a, b; cin >> a >> b;

		G[a].push_back(b);
	}

	memset(cnt, -1, sizeof cnt);
	cnt[1] = 0;

	queue<int> q; q.push(1);

	while (q.size()) {
		int now = q.front(); q.pop();
		for (int next : G[now]) {
			if (vst[next]) continue;
			vst[next] = 1;
			cnt[next] = cnt[now] + 1;
			q.push(next);
		}
	}

	cout << cnt[N];

}
