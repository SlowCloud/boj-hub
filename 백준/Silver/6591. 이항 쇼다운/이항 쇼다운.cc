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

/*

aCb

a! / (a-b)! / b!
(1/a) mod p = a^(p-1) mod p

아 int 안이면..

*/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	while (1) {
		ll a, b; cin >> a >> b;
		if (a == 0) break;

		ll res = 1;
		b = min(b, a - b);
		FOR(i, 0, b) {
			res *= (a - i);
			res /= (i + 1);
		}

		cout << res << endl;

	}

}

