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


ll dp[11'111]; // dp[price] = max cal;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	while (1) {

		memset(dp, 0, sizeof dp);

		int n; cin >> n;
		int m;
		string s; cin >> s;
		s.erase(s.end() - 3);
		m = stoi(s);

		if (n == 0) break;

		FOR(i, 0, n) {
			int a; cin >> a; // cal
			int b;
			string s; cin >> s;
			s.erase(s.end() - 3);
			b = stoi(s);

			FOR(j,0,m+1) {
				if (j + b > m) break;
				dp[j + b] = max(dp[j + b], dp[j] + a);
			}
		}

		cout << dp[m] << endl;

	}


}

