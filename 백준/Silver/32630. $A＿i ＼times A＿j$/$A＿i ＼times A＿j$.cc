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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<ll> v(N);
	ll now = 0;

	for (auto& i : v) {
		cin >> i;
		now += i;
	}

	sort(all(v));

	// 음수 2개 체크
	ll lmax = now;
	ll a, b;
	a = v[0]; b = v[1];
	lmax = now - a - b + a * b * 2;


	// 양수 2개 체크
	ll rmax = now;
	ll c, d;
	c = v[v.size() - 1]; d = v[v.size() - 2];
	rmax = now - c - d + c * d * 2;

	cout << max({ now, lmax, rmax });

}
