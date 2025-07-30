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

	int N, K; cin >> N >> K;

	int cnt = 0;
	vector<int> v;
	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		int gap = b - a;
		if (gap <= 0) {
			cnt++; continue;
		}
		v.push_back(gap);
	}

	sort(all(v));

	int rest = K - cnt;
	if (rest <= 0) {
		cout << 0; exit(0);
	}

	cout << v[rest - 1];

}

