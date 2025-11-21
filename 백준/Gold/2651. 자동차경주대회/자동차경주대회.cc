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


ll dp[111];
int p[111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	fill(dp, dp + 111, LLONG_MAX);
	p[0] = -1;
	dp[0] = 0;

	int max_distance; cin >> max_distance;

	int N; cin >> N;
	vector<ll> distance(N + 2), fix_time(N + 2);
	FOR(i, 1, N + 2) cin >> distance[i];
	FOR(i, 1, N + 1) cin >> fix_time[i];

	FOR(i, 0, N + 2) {
		ll total_distance = 0;
		FOR(j, i + 1, N + 2) {
			total_distance += distance[j];
			if (total_distance > max_distance) break;
			if (dp[j] > dp[i] + fix_time[j]) {
				p[j] = i;
				dp[j] = dp[i] + fix_time[j];
			}
		}
	}

	cout << dp[N + 1] << endl;

	stack<int> st;
	for (int now = p[N + 1]; now != 0; now = p[now]) {
		st.push(now);
	}
	cout << st.size() << endl;
	while (st.size()) {
		cout << st.top() << ' '; st.pop();
	}

}
