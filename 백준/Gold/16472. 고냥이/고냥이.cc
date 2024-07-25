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

int m[33];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	string s; cin >> s;

	int l, r;
	l = r = 0;

	int res = 0;
	int cnt = 0;
	while (r < s.size()) {
		while (cnt <= N && r < s.size()) {
			if (!m[s[r] - 'a']) {
				cnt++;
			}
			m[s[r] - 'a']++;
			r++;
		}
		res = max(res, r - l - 1);
		while (cnt > N) {
			m[s[l] - 'a']--;
			if (!m[s[l] - 'a']) {
				cnt--;
			}
			l++;
		}
	}
	res = max(r - l, res);

	cout << res;

}