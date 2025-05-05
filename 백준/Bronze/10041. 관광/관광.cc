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

	int W, H, N;
	cin >> W >> H >> N;

	vector<pii> v;
	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
	}

	auto calc = [&](pii a, pii b) -> int {
		if (a.first > b.first) swap(a, b);
		if (a.second > b.second) { // 좌상
			return b.first - a.first + a.second - b.second;
		}
		else { // 우상
			return max(b.first - a.first, b.second - a.second);
		}
	};

	int res = 0;
	FOR(i, 1, N) {
		res += calc(v[i - 1], v[i]);
	}

	cout << res;

}

