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


/*

1*9 + 2*90 + 3*900 + ... + 9*9e8

1~9 9 * 1
10~99 90 * 2
100~999 900 * 3
1000~9999 9000 * 4
...

1 0,0
10 9,10
100 209,211

*/

int size(ll n) {
	int cnt = 0;
	while (n) {
		cnt++; n /= 10;
	}
	return cnt;
}

/// <summary>
/// 
/// </summary>
/// <param name="n">숫자</param>
/// <returns>해당 숫자가 시작하는 인덱스</returns>
pll calc(ll n) {

	if (n < 10) {
		return { n - 1, n - 1 };
	}

	ll idx = 0;
	ll length = size(n);

	// 1~9
	idx += 9;
	FOR(i, 2, length) {
		idx += i * ((ll)pow(10, i - 1) * 9);
	}

	ll last = (n / (ll)pow(10, length - 1));

	// 10~19
	idx += length * (last - 1) * (ll)pow(10, length - 1);
	// 20~21
	idx += length * (n % (ll)pow(10, length - 1));

	return { idx, idx + length - 1 };
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, k; cin >> N >> k;
	k--;

	int l, r;
	l = 1; r = N;
	while (l <= r) {
		int m = l + r >> 1;
		auto [s, e] = calc(m);
		if (s <= k && k <= e) {
			string now = to_string(m);
			cout << now[k - s]; exit(0);
		}
		if (k < s) r = m - 1;
		else if (e < k) l = m + 1;
		else break;
	}
	cout << -1;

}
