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

	int N; cin >> N;

	int a, b, mx;
	a = b = mx = 0;
	
	vector<int> ls(N), rs(N);
	for (auto& i : ls) cin >> i;
	for (auto& i : rs) cin >> i;

	FOR(i, 0, N) {
		int l = ls[i], r = rs[i];
		if (l == 1 && r == 2 || l == 2 && r == 3 || l == 3 && r == 1) {
			a++; b = 0;
			mx = max({ a,b,mx });
		}
		else if (r == 1 && l == 2 || r == 2 && l == 3 || r == 3 && l == 1) {
			b++; a = 0;
			mx = max({ a,b,mx });
		}
		else {
			if (a == 0) a++, b = 0;
			else b++, a = 0;
			mx = max({ a,b,mx });
		}
	}
	cout << mx;

}
