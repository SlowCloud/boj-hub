#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

#define FAST ios::sync_with_stdio(0); cin.tie(0);

#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define reduce(v) v.erase(unique(all(v)), v.end())

pll dots[100'000];
set<pll> sweep;

pll rev(pll a) {
	return { a.second, a.first };
}

ll power(ll a) {
	return a * a;
}

ll gap(pll a, pll b) {
	return power(a.first - b.first) + power(a.second - b.second);
}

int main() {
	FAST;

	int N; cin >> N;
	for (int i = 0; i < N; i++) cin >> dots[i].first >> dots[i].second;
	sort(dots, dots + N);

	ll ans = 9e18;

	// 이렇게 스위핑 하는 방법이 있네.. 허참
	int j = 0;
	for (int i = 0; i < N; i++) {
		while (dots[i].first - dots[j].first > sqrt(ans)) {
			sweep.erase(rev(dots[j++]));
		}

		if (!sweep.empty()) {
			auto iter = sweep.lower_bound({ dots[i].second - sqrt(ans) - 1, 2e9 });
			while (iter != sweep.end() && iter->first <= dots[i].second + sqrt(ans) + 1) {
				ans = min(ans, gap(dots[i], rev(*iter)));
				iter++;
			}
		}

		sweep.insert(rev(dots[i]));
	}

	cout << ans;

} // main