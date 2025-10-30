#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



// 1-based
ll calc(const ll& r, const ll& c, const ll& N) {
	const bool odd = (r + c) & 1;
	ll nth = r + c - 1;
	if (r + c <= N + 1) {
		ll res = nth * (nth - 1) / 2;
		res += (!odd ? c : r);
		return res;
	}
	else {
		nth = N * 2 - nth;
		ll res = N * N - nth * (nth + 1) / 2;
		res += N - (odd ? c : r) + 1;
		return res;
	}
}


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K; cin >> N >> K;

	string s; cin >> s;

	int x = 1, y = 1;
	ll res = 1;
	for(char c : s) {
		x += c == 'D';
		x -= c == 'U';
		y += c == 'R';
		y -= c == 'L';
		res += calc(x, y, N);
		// cout << calc(x, y, N) << endl;
	}
	cout << res;

}
