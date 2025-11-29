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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	vector<pll> dots(M);
	for (auto& i : dots) cin >> i.first >> i.second;

	vector<ll> x, y;
	for (const auto& dot : dots) {
		x.push_back(dot.first);
		y.push_back(dot.second);
	}

	sort(all(x));
	sort(all(y));

	pll target = { x[M / 2], y[M / 2] };

	ll res = 0;
	for (const auto& dot : dots) {
		res += abs(target.first - dot.first) + abs(target.second - dot.second);
	}

	cout << res;

}
