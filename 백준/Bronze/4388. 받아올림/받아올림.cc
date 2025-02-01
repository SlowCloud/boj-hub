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

	while (true) {
		int a, b; cin >> a >> b;
		if (a == b && a == 0) break;

		if (a < b) swap(a, b);

		vector<int> l, r;
		while (a) {
			l.push_back(a % 10); a /= 10;
		}
		while (b) {
			r.push_back(b % 10); b /= 10;
		}

		int res = 0;

		FOR(i, 0, l.size()) {
			int now = l[i] + (i < r.size()? r[i] : 0);
			now /= 10;
			if (now) {
				res += now;
				if (i < l.size() - 1) {
					l[i + 1] += now;
				}
			}
		}

		cout << res << endl;

	}


}
