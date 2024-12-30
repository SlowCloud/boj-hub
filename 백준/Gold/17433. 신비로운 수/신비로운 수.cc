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

		int N; cin >> N;
		vector<int> v(N);
		for (auto& i : v) cin >> i;

		vector<int> w;

		FOR(i, 1, N) {
			int now = v[i] - v[i - 1];
			if (now) {
				w.push_back(now);
			}
		}

		if (w.empty()) {
			cout << "INFINITY" << endl; continue;
		}

		int res = 0;
		FOR(i, 0, w.size()) {
			res = gcd(res, w[i]);
		}

		cout << res << endl;
	}

}
