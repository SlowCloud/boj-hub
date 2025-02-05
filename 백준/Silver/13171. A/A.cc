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



constexpr ll MOD = 1e9 + 7;

ll mul(ll a, ll b) {
	a %= MOD;
	if (b == 0) return 1;
	if (b & 1) {
		return mul(a, b - 1) * a % MOD;
	}
	ll tmp = mul(a, b / 2);
	return tmp * tmp % MOD;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll a, b; cin >> a >> b;
	cout << mul(a, b);

}
