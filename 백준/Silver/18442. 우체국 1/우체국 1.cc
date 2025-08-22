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

	ll V, P, L; cin >> V >> P >> L;

	vector<ll> v(V);
	for (auto& i : v) cin >> i;


	vector<int> rand(V);
	fill(rand.begin(), rand.begin() + P, 1);
	sort(rall(rand));

	ll res = 1e18;
	vector<ll> target;
	do {

		vector<ll> targets;
		FOR(i, 0, V) {
			if (rand[i]) targets.push_back(v[i]);
		}

		ll tmp = 0;
		for (const auto& i : v) {
			ll now = 1e18;
			for (const auto& j : targets) {
				now = min({ now, abs(i - j), L - abs(i - j) });
			}
			tmp += now;
		}

		if (res > tmp) {
			res = tmp;
			target = targets;
		}

	} while (next_permutation(rall(rand)));

	cout << res << endl;
	for (const auto& i : target) cout << i << ' ';

}
