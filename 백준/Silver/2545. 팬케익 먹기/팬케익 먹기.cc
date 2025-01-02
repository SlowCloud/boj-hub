#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		ll A, B, C; cin >> A >> B >> C;
		ll D; cin >> D;
		while (D--) {
			ll ab = A * B;
			ll ac = A * C;
			ll bc = B * C;
			ll mn = min({ ab,ac,bc });
			if (ab < ac && ab < bc) {
				C--; continue;
			}
			else if (ac < ab && ac < bc) {
				B--; continue;
			}
			else if (bc < ac && bc < ab) {
				A--; continue;
			}
			else {
				if (ab == mn) C--;
				else if (ac == mn) B--;
				else A--;
			}
		}
		cout << A * B * C << endl;
	}

}
