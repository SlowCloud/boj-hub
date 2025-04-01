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

	vector<int> v(N); for (auto& i : v) cin >> i;

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if (i == j) continue;
			FOR(k, 0, N) {
				if (k == i) continue;
				if (k == j) continue;

				if ((v[i] - v[j]) % v[k]) {
					cout << "no"; return 0;
				}

			}
		}
	}

	cout << "yes";

}

