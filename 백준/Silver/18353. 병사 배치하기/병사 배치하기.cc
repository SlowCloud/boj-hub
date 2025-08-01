#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int dp[2222];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	fill(dp, dp + 2222, 1);

	FOR(i, 0, N) {
		FOR(j, 0, i) {
			if (v[j] > v[i]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	cout << N - *max_element(dp, dp+2222);


}
