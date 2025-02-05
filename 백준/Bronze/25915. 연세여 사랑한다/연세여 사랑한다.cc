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

	const string s = "ILOVEYONSEI";

	char c; cin >> c;

	int res = 0;
	for (char cc : s) {
		res += abs(c - cc);
		c = cc;
	}

	cout << res;

}
