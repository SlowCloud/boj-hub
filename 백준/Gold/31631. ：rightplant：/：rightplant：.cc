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

	vector<int> v(N, 1);

	int l, r, n, flip;
	l = n = flip = 0;
	r = N - 1;
	n = N;

	while (l < r) {
		if (flip) {
			v[l] = n; v[r] = n - 1;
		}
		else {
			v[r] = n; v[l] = n - 1;
		}
		flip ^= 1;
		l++; r--;
		n -= 2;
	}

	for (auto& i : v) cout << i << ' ';


}

