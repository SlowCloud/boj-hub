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


int d[111'111];

vector<int> G[111'111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K; cin >> N >> K;

	FOR(i, 1, N) {
		int a, b; cin >> a >> b;
		G[a].push_back(b);
	}

	queue<int> q; q.push(0);
	while (q.size()) {
		int now = q.front(); q.pop();
		for (int next : G[now]) {
			d[next] = d[now] + 1;
			q.push(next);
		}
	}

	FOR(i, 0, N) {
		int n; cin >> n;
		if (n == K) {
			cout << d[i]; exit(0);
		}
	}


}
