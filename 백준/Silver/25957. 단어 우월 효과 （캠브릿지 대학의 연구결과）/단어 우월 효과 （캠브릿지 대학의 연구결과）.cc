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

	map<string, string> dp;
	int N; cin >> N;
	while (N--) {
		string s; cin >> s;
		string ss = s;
		if(ss.size() > 3) sort(ss.begin() + 1, ss.end() - 1);
		dp[ss] = s;
	}

	int M; cin >> M;
	while (M--) {
		string s; cin >> s;
		string ss = s;
		if(ss.size() > 3) sort(ss.begin() + 1, ss.end() - 1);
		cout << dp[ss] << ' ';
	}

}
