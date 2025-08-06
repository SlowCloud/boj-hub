#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int a, b, c; cin >> a >> b >> c;

	int res = 0;

	res += a / 3; a %= 3;
	res += b / 3; b %= 3;
	res += c / 3; c %= 3;

	vector<int> v{ a,b,c };
	sort(rall(v));

	int tmp = max(v[1], v[2]);
	res += tmp;

	res += !!(v[0] - tmp);

	cout << res;

}
