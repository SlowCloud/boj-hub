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
	string s; cin >> s;

	if (N % 2) {
		cout << -1; return 0;
	}

	int res = 0;
	int num = 0;

	for (char c : s) {
		num += c == '(';
		num -= c == ')';
		res = max(res, abs(num));
	}

	if (num != 0) {
		cout << -1;
	}
	else {
		cout << res;
	}

}
