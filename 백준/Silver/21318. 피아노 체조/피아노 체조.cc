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


int dp[111'111];
int m[111'111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 1, N + 1) cin >> m[i];

	FOR(i, 1, N) {
		if (m[i] > m[i + 1]) dp[i]++;
	}

	FOR(i, 1, N + 1) dp[i] += dp[i - 1];

	int Q; cin >> Q;
	while (Q--) {
		int a, b; cin >> a >> b;
		cout << dp[b] - dp[a] - (b < N && m[b] > m[b+1]) + (a < N && m[a] > m[a+1]) << endl;
	}


}
