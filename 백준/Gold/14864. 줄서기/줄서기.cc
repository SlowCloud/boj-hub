#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	vector<pii> edges;
	vector<int> cnt(N);

	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		a--; b--;
		cnt[a]++;
		edges.push_back({ a,b });
	}

	set<int> s;
	FOR(i, 1, N + 1) s.insert(i);

	vector<int> v;
	FOR(i, 0, N) { // N^2긴 한데
		auto iter = s.begin();
		iter = next(iter, cnt[i]);
		int now = *iter;
		v.push_back(now); s.erase(now);
	}

	for (auto& edge : edges) {
		auto [a, b] = edge;
		if (v[a] < v[b]) {
			cout << -1; exit(0);
		}
	}
	for (auto& i : v) cout << i << ' ';

}
