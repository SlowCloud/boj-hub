#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
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

	vector<int> l, r;

	int N; cin >> N;
	FOR(i, 0, N) {
		int n; cin >> n;
		l.push_back(n);
	}
	int M; cin >> M;
	FOR(i, 0, M) {
		int n; cin >> n;
		r.push_back(n);
	}

	ll res = 1;
	FOR(i, 0, N) {
		FOR(j, 0, M) {
			int now = gcd(l[i], r[j]);
			res *= now;
			res %= (ll)1e10;
			l[i] /= now;
			r[j] /= now;
		}
	}

	string sres = to_string(res);
	if (sres.size() > 9) sres = sres.substr(sres.size() - 9);
	cout << sres;

}
