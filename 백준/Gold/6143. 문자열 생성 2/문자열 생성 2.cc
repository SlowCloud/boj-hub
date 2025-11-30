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


unordered_map<int, unordered_map<int, string>> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	vector<char> v(N);
	for (auto& i : v) cin >> i;

	int l = 0, r = N - 1;
	string res;

	const auto cmp = [&](int l, int r) -> bool {
		while (l <= r && v[l] == v[r]) {
			l++; r--;
		}
		if (l > r) return true;
		return v[l] < v[r];
	};

	while (l <= r) {
		if (cmp(l, r)) {
			res += v[l]; l++;
		}
		else {
			res += v[r]; r--;
		}
	}
	FOR(i, 0, res.size()) {
		cout << res[i];
		if ((i + 1) % 80 == 0) cout << endl;
	}

}
