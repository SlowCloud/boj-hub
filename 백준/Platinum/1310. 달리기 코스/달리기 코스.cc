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

// 07:40
// 1310

// 반시계 양수
int ccw(pll a, pll b, pll c) {
	ll t = (a.first - b.first) * (c.second - b.second) - (a.second - b.second) * (c.first - b.first);
	return (t > 0) - (t < 0);
}

ll cccw(pll a, pll b, pll c, pll d) {
	d.first -= c.first - b.first;
	d.second -= c.second - b.second;
	return ccw(a, b, d);
}

ll dist(pll a, pll b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

vector<pll> dots, convex;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	For(i, 0, N) {
		ll a, b; cin >> a >> b;
		dots.push_back({ a,b });
	}
	sort(all(dots));

	// 반시계 정렬
	auto cmp = [&](const pll& a, const pll& b) {
		int t = ccw(dots[0], a, b);
		if (t == 0) {
			return dist(dots[0], a) < dist(dots[0], b);
		}
		return t < 0;
	};
	sort(dots.begin() + 1, dots.end(), cmp);

	//for (auto& dot : dots) {
	//	cout << dot.first << ' ' << dot.second << endl;
	//}

	for (auto& dot : dots) {
		while (convex.size() >= 2 && ccw(convex[convex.size() - 2], convex[convex.size() - 1], dot) >= 0) {
			convex.pop_back();
		}
		convex.push_back(dot);
	}

	//for (auto& dot : convex) {
	//	cout << dot.first << ' ' << dot.second << endl;
	//}

	ll far = 0;
	int opp = 1;
	For(i, 0, convex.size()) {
		while (opp + 1 != i && cccw(convex[i], convex[(i + 1) % convex.size()], convex[opp % convex.size()], convex[(opp + 1) % convex.size()]) < 0) {
			if (far < dist(convex[i], convex[opp % convex.size()])) {
				far = dist(convex[i], convex[opp % convex.size()]);
			}
			opp++;
		}
		if (far < dist(convex[i], convex[opp % convex.size()])) {
			far = dist(convex[i], convex[opp % convex.size()]);
		}
	}

	cout << far;

}