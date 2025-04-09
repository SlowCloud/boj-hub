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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<int> v;
	FOR(i, 0, N) {
		int n; cin >> n; v.push_back(n);
	}
	sort(all(v));
	v.erase(unique(all(v)), v.end());

	set<int> sum;
	FOR(i, 0, v.size()) {
		FOR(j, i, v.size()) {
			sum.insert(v[i] + v[j]);
		}
	}

	// sum[t] = for i for j v[i] + v[j]
	// sum[i] + v[j] = v[k]
	// sum[i] = v[k] - v[j], j < k (음수가 없으므로 자명함)

	for (int i = v.size() - 1; i >= 0; i--) {
		for (int j = i; j >= 0; j--) {
			if (sum.count(v[i] - v[j])) {
				cout << v[i]; exit(0);
			}
		}
	}

}
