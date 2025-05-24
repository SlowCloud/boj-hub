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

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	ll res = 0;
	res += N * 2; // top, bottom
	res += v[0] + v.back(); // left, right

	for (const auto& i : v) res += i * 2; // back, front

	FOR(i, 1, v.size()) {
		res += abs(v[i] - v[i - 1]);
	}

	cout << res;

}

