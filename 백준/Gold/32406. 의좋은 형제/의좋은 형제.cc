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




int main() {
	cin.tie(0)->sync_with_stdio(0);


	vector<int> a, b;
	int N; cin >> N;

	FOR(i, 0, N) {
		int n; cin >> n;
		a.push_back(n);
	}
	FOR(i, 0, N) {
		int n; cin >> n;
		b.push_back(n);
	}

	for (int i = 0; i < N; i += 2) {
		swap(a[i], b[i]);
	}

	FOR(i, 0, N - 2) {
		if (a[i] > b[i]) swap(a[i], b[i]);
	}
	int l = 0;
	FOR(i, 0, N) l += a[i] - b[i];
	l = abs(l);

	FOR(i, 0, N - 2) {
		if (a[i] < b[i]) swap(a[i], b[i]);
	}
	int r = 0;
	FOR(i, 0, N) r += a[i] - b[i];
	r = abs(r);

	cout << max(l, r);

}
