#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
#include <algorithm>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int dp[666'666];

struct Contest {
	int s, e, c;
};

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<Contest> contests(N);
	for (auto& c : contests) {
		cin >> c.s >> c.e >> c.c;
	}

	vector<int> x;
	for (const auto& contest : contests) {
		x.push_back(contest.s);
		x.push_back(contest.e);
	}
	sort(all(x));
	x.erase(unique(all(x)), x.end());
	for(auto& contest : contests) {
		contest.s = lower_bound(all(x), contest.s) - x.begin();
		contest.e = lower_bound(all(x), contest.e) - x.begin();
	}

	sort(all(contests), [](const Contest& a, const Contest& b) {
		return a.e < b.e;
	});

	int idx = 1;
	for (const auto& contest : contests) {
		while (idx <= contest.e) {
			dp[idx] = max(dp[idx], dp[idx - 1]);
			idx++;
		}
		dp[contest.e] = max(dp[contest.e], (contest.s? dp[contest.s - 1] : 0) + contest.c);
	}

	cout << dp[x.size() - 1];

}
