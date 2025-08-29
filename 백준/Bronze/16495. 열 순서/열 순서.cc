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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s; cin >> s;

	ll res = 0;
	ll tmp = pow(26, s.size() - 1);
	for(const char& c : s) {
		res += tmp * (c - 'A' + 1);
		tmp /= 26;
	}

	cout << res;

}
