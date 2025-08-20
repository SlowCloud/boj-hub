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


constexpr int MOD = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int D; cin >> D;
	vector<int> v(D);
	for (auto& i : v) cin >> i;

	ll layer_count = 1;
	ll now = 1;
	ll left = 1;
	vector<int> res{ 1 };

	FOR(i, 1, D) {
		ll begin = (left + layer_count) % MOD;
		ll sub = ((left * (i + 1)) % MOD - begin + MOD) % MOD;
		left = begin;

		ll next = (now * (i + 1)) % MOD + v[i] - 1 - sub + MOD;
		next %= MOD;

		res.push_back(next);
		now = next;

		layer_count *= (i + 1);
		layer_count %= MOD;
	}

	for (const auto& i : res) cout << i << endl;

}
