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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	vector<int> v(N);
	for (auto& i : v) cin >> i;

	vector<int> idx(N + 1);
	FOR(i, 0, v.size()) {
		idx[v[i]] = i;
	}

	int res = 1;
	int now = 1;
	FOR(i, 2, idx.size()) {
		if (idx[i] > idx[i - 1]) {
			now++; res = max(now, res);
		}
		else {
			now = 1;
		}
	}

	cout << N - res;

}

