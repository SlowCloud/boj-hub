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


ll dp[11'111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, Q; cin >> N >> Q;

	while (Q--) {
		ll a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			dp[b] += c;
		}
		else {
			ll res = 0;
			FOR(i, b, c + 1) {
				res += dp[i];
			}
			cout << res << endl;
		}
	}

}

