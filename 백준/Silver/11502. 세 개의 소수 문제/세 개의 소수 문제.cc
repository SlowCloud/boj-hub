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

vector<int> primes;

int m[1111];
void build() {
	FOR(i, 2, 1111) {
		if (m[i]) continue;
		m[i] = 1;
		primes.push_back(i);
		for (int j = i; j < 1111; j += i) m[j] = 1;
	}
}

void solve() {
		int n; cin >> n;
		FOR(i, 0, primes.size()) FOR(j, i, primes.size()) FOR(k, j, primes.size()) {
			int now = primes[i] + primes[j] + primes[k];
			if (now == n) {
				cout << primes[i] << ' ' << primes[j] << ' ' << primes[k] << endl;
				return;
			}
		}
		cout << 0 << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	build();

	int T; cin >> T;
	while (T--) {
		solve();
	}


}
