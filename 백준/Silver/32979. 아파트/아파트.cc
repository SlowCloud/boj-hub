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
	int T; cin >> T;

	vector<int> v(N << 1);
	for (auto& i : v) cin >> i;

	vector<int> res;
	int idx = 0;
	FOR(i, 0, T) {
		int n; cin >> n;
		idx = (idx + n - 1) % (N << 1);
		res.push_back(v[idx]);
	}

	for (auto& i : res) cout << i << ' ';

}

