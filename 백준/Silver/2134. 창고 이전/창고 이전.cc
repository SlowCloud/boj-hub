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

	int N, M, K; cin >> N >> M >> K;

	vector<int> v(N);
	int vsum = 0;
	for (auto& i : v) {
		cin >> i;
		vsum += i;
	}

	vector<int> w(M);
	int wsum = 0;
	for (auto& i : w) {
		cin >> i;
		wsum += i;
	}

	int total = min(vsum, wsum);
	cout << total << ' ';

	ll times = 0;
	int l, r;
	l = r = 0;
	while (l < v.size() && r < w.size()) {
		int m = min(v[l], w[r]);
		times += (long long)(l + r + 2) * m;
		v[l] -= m; w[r] -= m;
		if (v[l] == 0) l++;
		if (w[r] == 0) r++;
	}

	cout << times;

}
