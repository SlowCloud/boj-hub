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

// https://www.acmicpc.net/problem/5911

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N; cin >> N;

	// edge
	if (N == 0) cout << "NO", exit(0);

	vector<ll> v;
	ll now = 1;
	FOR(i, 0, 21) {
		v.push_back(now);
		now *= 3;
		if (now > N) break;
	}

	for (int i = 0; i < (1 << v.size()); i++) {
		ll now = 0;
		FOR(k, 0, v.size()) {
			if (i & (1 << k)) {
				now += v[k];
			}
			if (now > N) break;
		}
		if (now == N) {
			cout << "YES"; exit(0);
		}
	}

	cout << "NO";

}
