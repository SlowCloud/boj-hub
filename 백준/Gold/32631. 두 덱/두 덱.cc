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


ll ma[5555], mb[5555];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	fill(ma + 1, ma + 5555, LLONG_MAX);
	fill(mb + 1, mb + 5555, LLONG_MAX);

	int N, K; cin >> N >> K;

	vector<ll> a, b;

	FOR(i, 0, N) {
		int n; cin >> n; a.push_back(n);
	}
	FOR(i, 0, N) {
		int n; cin >> n; b.push_back(n);
	}

	FOR(i, 0, N) {
		ll sum = 0;
		FOR(j, i, N) {
			int size = j - i + 1;
			sum += a[j];
			ma[size] = min(ma[size], sum);
		}
	}

	FOR(i, 0, N) {
		ll sum = 0;
		FOR(j, i, N) {
			int size = j - i + 1;
			sum += b[j];
			mb[size] = min(mb[size], sum);
		}
	}

	ll res = LLONG_MAX;
	FOR(i, 0, K + 1) {
		int j = K - i;

		int l = max(0, N - i);
		int r = max(0, N - j);
		res = min(res, max(ma[l], mb[r]));
	}

	cout << res;

}
