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

	int N, L, R; cin >> N >> L >> R;
	vector<int> v(N);
	for (auto& i : v) cin >> i;
	sort(v.begin() + L - 1, v.begin() + R);

	FOR(i, 0, v.size() - 1) {
		if (v[i] > v[i + 1]) {
			cout << 0; exit(0);
		}
	}
	cout << 1;

}
