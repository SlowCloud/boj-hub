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



int m[44'444];
vector<int> primes;

void build() {
	FOR(i, 2, 44'444) {
		if (m[i]) continue;
		primes.push_back(i);
		for (int j = i; j < 44'444; j += i) {
			m[j] = 1;
		}
	}
}

int dp[44'444];

constexpr int MOD = 123'456'789;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	build();
	dp[0] = 1;

	for (const auto& prime : primes) {
		FOR(i,0,44'444) {
			if (i + prime >= 44'444) break;
			dp[i + prime] += dp[i];
			dp[i + prime] %= MOD;
		}
	}

	int N; cin >> N;
	cout << dp[N];

}
