#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

#define FAST ios::sync_with_stdio(0);
#define NOTIE cin.tie(0);

#define endl '\n'
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define reduce(v) v.erase(unique(all(v)), v.end())

ll dp[300'000][3], N;

// 트리의 구간합? 초기화
void init() {
	int idx = (N >> 1);
	while (idx) {
		dp[idx][1] = dp[idx][0] +  max(dp[idx << 1][1], dp[idx << 1 | 1][1]);
		dp[idx][2] = max({ dp[idx][0] + dp[idx << 1][1] + dp[idx << 1 | 1][1], dp[idx << 1][2], dp[idx << 1 | 1][2]});
		--idx;
	}
}

// 갱신
void update(int idx, ll v) {
	dp[idx][0] = dp[idx][1] = dp[idx][2] = v;
	if (idx > N >> 1) idx >>= 1;
	while (idx) {
		dp[idx][1] = dp[idx][0] + max(dp[idx << 1][1], dp[idx << 1 | 1][1]);
		dp[idx][2] = max({ dp[idx][0] + dp[idx << 1][1] + dp[idx << 1 | 1][1], dp[idx << 1][2], dp[idx << 1 | 1][2] });
		idx >>= 1;
	}
}

int main() {
	FAST; NOTIE;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> dp[i][0];
		dp[i][2] = dp[i][1] = dp[i][0];
	}

	init();
	cout << dp[1][2] << endl;

	int Q; cin >> Q;
	while (Q--) {
		ll i, d; cin >> i >> d;
		update(i, d);
		cout << dp[1][2] << endl;
	}

} // main