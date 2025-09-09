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

int main() {
	cin.tie(0)->sync_with_stdio(0);

	FOR(i, 1, 111'111) {
		dp[i] = 1e9;
		for (const int& n : { 7,5,2,1 }) {
			int idx = i - n;
			if (idx < 0) continue;
			dp[i] = min(dp[i], dp[idx] + 1);
		}
	}

	int N; cin >> N;
	cout << dp[N];

}
