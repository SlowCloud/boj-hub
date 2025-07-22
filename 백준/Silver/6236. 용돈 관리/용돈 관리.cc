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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	ll sum = 0;

	vector<int> v;
	FOR(i, 0, N) {
		int n; cin >> n;
		v.push_back(n);
	}

	ll l = 1, r = 1e18, m;
	FOR(i, 0, N) {
		l = max(l, (ll)v[i]);
	}
	while (l <= r) {
		m = l + r >> 1;

		int cnt = 1;
		int now = 0;
		FOR(i, 0, N) {
			now += v[i];
			if (now > m) {
				cnt++;
				now = v[i];
			}
		}

		if (cnt <= M) r = m - 1;
		else l = m + 1;
	}

	cout << l;

}
