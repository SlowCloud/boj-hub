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


ll f(ll l) {
	return l * (l - 1) / 2;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	ll N, L; cin >> N >> L;

	FOR(l, L, 101) {
		ll tmp = f(l);
		if ((N - tmp >= 0) && (N - tmp) % l == 0) {
			ll x = (N - tmp) / l;
			FOR(k, 0, l) {
				cout << x + k << ' ';
			}
			exit(0);
		}
	}
	cout << -1;

}
