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

	int N, Q, U, V; cin >> N >> Q >> U >> V;

	vector<ll> v(N);
	for (auto& i : v) cin >> i;

	while (Q--) {
		int a, b, c; cin >> a >> b >> c;
		if (a == 0) {
			ll res = LLONG_MIN;
			FOR(i, b - 1, c) {
				ll uu, vv;
				uu = 0;
				vv = -1;
				FOR(j, i, c) {
					uu += v[j]; vv++;
					res = max(res, uu * U + vv * V);
				}
			}
			cout << res << endl;
		}
		else {
			v[b - 1] = c;
		}
	}

}
