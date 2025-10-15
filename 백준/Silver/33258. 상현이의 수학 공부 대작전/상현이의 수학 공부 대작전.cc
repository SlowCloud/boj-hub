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

	int N; cin >> N;

	vector<int> A(N);
	for (auto& i : A) cin >> i;

	ll L; cin >> L;

	ll l, r, m;
	l = 0, r = 1e9;

	while (l <= r) {
		m = l + r >> 1;

		ll now = 0;
		for (const auto& a : A) {
			now += m < a ? 2 * (m - a) : m;
		}

		if (now < L) l = m + 1;
		else r = m - 1;
		
	}

	cout << l;

}
