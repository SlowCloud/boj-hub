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


vector<pii> G[5555];
int vst[5555];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q; cin >> N >> Q;

	FOR(i, 1, N) {
		int a, b, c; cin >> a >> b >> c;
		G[a].push_back({ c,b });
		G[b].push_back({ c,a });
	}

	FOR(i, 0, Q) {
		int a, b; cin >> a >> b;
		memset(vst, 0, sizeof vst);

		queue<int> q; q.push(b);
		vst[b] = 1;
		int res = 0;

		while (q.size()) {
			int now = q.front(); q.pop();
			for (const auto& [w, next] : G[now]) {
				if (w < a) continue;
				if (vst[next]) continue;
				vst[next] = 1;
				q.push(next);
				res++;
			}
		}

		cout << res << endl;

	}


}
