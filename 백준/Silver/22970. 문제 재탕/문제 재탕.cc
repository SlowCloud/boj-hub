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


int dp1[5555], dp2[5555];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<int> v(N);
	for (auto& i : v) cin >> i;

	FOR(i, 0, N) {
		dp1[i] = 1;
		if (!i) continue;
		if (v[i - 1] < v[i]) {
			dp1[i] = dp1[i - 1] + 1;
		}
	}

	for (int i = N - 1; i >= 0; i--) {
		dp2[i] = 1;
		if (i == N - 1) continue;
		if (v[i] > v[i + 1]) {
			dp2[i] = dp2[i + 1] + 1;
		}
	}

	int res = 0;
	FOR(i, 0, N) {
		res = max(res, dp1[i] + dp2[i] - 1);
	}
	cout << res;

}
