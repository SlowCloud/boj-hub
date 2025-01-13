#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
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

	int N, Q; cin >> N >> Q;

	string s; cin >> s;

	while (Q--) {
		int op, l, r;
		cin >> op >> l >> r;
		l--;

		if (op == 1) {
			char now = '1';
			int res = 0;
			FOR(i, l, r) {
				if (now != s[i]) {
					now = s[i];
					res++;
				}
			}
			cout << res << endl;
		}
		if (op == 2) {
			FOR(i, l, r) {
				int c = s[i];
				s[i] = (c - 'A' + 1) % 26 + 'A';
			}
		}

	}

}
