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

#define FOR_(type,i, a, b) for(type i=a;i<b;i++)
#define FOR(i,a,b) FOR_(int,i,a,b)
#define FORLL(i,a,b) FOR_(ll,i,a,b)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'



vector<pll> A, B;

static int find_idx(const vector<pll>& v, int x) {
	int l = 0, r = (int)v.size() - 1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (v[m].first <= x) l = m + 1;
		else r = m - 1;
	}
	return l - 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	FOR(i, 0, N) {
		int idx, x; cin >> idx >> x;
		A.push_back({ idx, x });
	}
	sort(all(A));
	int M; cin >> M;
	FOR(i, 0, M) {
		int idx, x; cin >> idx >> x;
		B.push_back({ idx, x });
	}
	B.push_back({ INT_MIN, 0 });
	sort(all(B));
	FOR(i, 1, B.size()) {
		B[i].second += B[i - 1].second;
	}

	int a, b; cin >> a >> b;
	ll res = 0;
	FOR(i, 0, N) {
		int l = find_idx(B, A[i].first + a - 1);
		int r = find_idx(B, A[i].first + b);
		res += A[i].second * (B[r].second - B[l].second);
		// cout << l << ' ' << r << ',' << B[r].second - B[l].second << endl;
	}
	cout << res;

}
