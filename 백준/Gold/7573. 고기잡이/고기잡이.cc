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


int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, I, M; cin >> N >> I >> M;

	vector<ii> fishes;

	For(i, 0, M) {
		int a, b; cin >> a >> b;
		fishes.push_back({ a,b });
	}

	int res = 0;

	for (const auto& fish : fishes) {
		auto [sx, sy] = fish;

		for (int r = 1; r < I / 2; r++) {
			int c = I / 2 - r;
			int ex = sx + r;
			int ey = sy + c;
			For(i, 0, 2 * N) {
				if (ex - i <= 0) break;
				sx -= i;
				ex -= i;
				int cnt = 0;
				for (auto& f : fishes) {
					cnt += sx <= f.first && f.first <= ex && sy <= f.second && f.second <= ey;
				}
				res = max(res, cnt);
				sx += i;
				ex += i;
			}
		}

	}

	cout << res;

}
