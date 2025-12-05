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


ll dp[222'222];

map<ll, int> pos;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, K; cin >> N >> K;

	FOR(i, 1, N + 1) cin >> dp[i];
	FOR(i, 2, N + 1) dp[i] += dp[i - 1];

	ll res = 0;
	FOR(i, 1, N + 1) {
		const auto& now = dp[i];
		if (pos.find(now - K) != pos.end()) {
			res += pos[now - K];
		}
		if (now == K) res++;
		pos[now]++;
	}

	cout << res;

}
