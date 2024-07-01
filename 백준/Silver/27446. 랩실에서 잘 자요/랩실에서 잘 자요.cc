#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define FOR(i,a,b) For(i,a,b)
#define For(i,a,b) for(int i=a;i<b;i++)
#define foi(i,n) for(int i=0;i<n;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


int m[111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	For(i, 0, M) {
		int n; cin >> n;
		m[n] = 1;
	}

	vector<int> v;
	For(i, 1, N + 1) {
		if (m[i] == 0) v.push_back(i);
	}

	int last = 0;
	int res = 0;
	for (auto& i : v) {
		if (last) {
			res += min(7, (i - last) * 2);
		}
		else {
			res += 7;
		}
		last = i;
	}
	cout << res;

}