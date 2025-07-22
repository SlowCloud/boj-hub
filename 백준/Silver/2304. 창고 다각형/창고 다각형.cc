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

	int N; cin >> N;

	vector<int> v(1111), w(1111, 1e9);

	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		v[a] = b;
	}

	int now = 0;
	FOR(i, 0, v.size()) {
		now = max(v[i], now);
		w[i] = min(w[i], now);
	}

	now = 0;
	for (int i = v.size() - 1; i >= 0; i--) {
		now = max(v[i], now);
		w[i] = min(w[i], now);
	}

	int res = 0;
	FOR(i, 0, w.size()) {
		res += w[i];
	}

	cout << res;

}
