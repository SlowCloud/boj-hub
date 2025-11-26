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

	int N; cin >> N;

	vector<int> v(N + 2);
	iota(all(v), 0);

	int end = N;
	int now = 1<<(int)log2(N);

	while (now >= 2) {
		int gap = end - now;
		if (gap >= 0) {
			reverse(v.begin() + now - gap, v.begin() + now + gap + 1);
			end = now - gap - 1;
		}
		now >>= 1;
	}

	FOR(i, 1, N + 1) cout << v[i] << ' ';

}
