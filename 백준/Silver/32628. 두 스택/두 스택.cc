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


ll a[111'111];
ll b[111'111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K;
	cin >> N >> K;

	FOR(i, 1, N + 1) {
		cin >> a[i];
		if (i) a[i] += a[i - 1];
	}
	FOR(i, 1, N + 1) {
		cin >> b[i];
		if (i) b[i] += b[i - 1];
	}
	
	ll res = max(a[N], b[N]);
	FOR(i, 0, K + 1) {
		int l = i, r = K - i;

		ll aa = a[max(0, N - l)];
		ll bb = b[max(0, N - r)];

		res = min(res, max(aa, bb));
	}

	cout << res;

}
