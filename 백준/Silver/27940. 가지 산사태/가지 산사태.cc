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

	int N, M, K; cin >> N >> M >> K;

	vector<pii> queries;
	FOR(i, 0, M) {
		int a, b; cin >> a >> b;
		queries.push_back({ a,b });
	}

	auto build = [&](int m) -> vector<int> {
		vector<int> v(N + 2);
		for (int i = 0; i <= m; i++) {
			auto [a, b] = queries[i];
			v[1] += b; v[a + 1] -= b;
		}
		FOR(i, 1, v.size()) {
			v[i] += v[i - 1];
		}
		return v;
	};

	int l = 0, r = M - 1;
	while (l <= r) {
		int m = l + r >> 1;
		auto v = build(m);
		bool fall = false;
		for (auto& i : v) {
			if (i > K) {
				fall = true; break;
			}
		}
		if (fall) r = m - 1;
		else l = m + 1;
	}

	if (l < M) {
		cout << l + 1 << ' ';

		auto v = build(l);
		FOR(i, 0, v.size()) {
			if (v[i] > K) {
				cout << i; break;
			}
		}
	}
	else {
		cout << -1;
	}

}

