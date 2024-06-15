#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <queue>
#include <numeric>
#include <cmath>
#include <stack>
#include <iomanip>
using namespace std;

#define For(i,a,b) for(int i=a;i<b;i++)
// #define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using ll = long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;


int ccw(pll a, pll b, pll c) {
	ll t = (a.first - b.first) * (c.second - b.second) - (a.second - b.second) * (c.first - b.first);
	return (t < 0) - (t > 0);
}

struct Dot {
	pll d; int idx;
	bool operator < (const Dot& dot) {
		return d < dot.d;
	}
};

vector<Dot> dots;

ll dist(pll a, pll b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		dots.clear();
		int N; cin >> N;
		For(i, 0, N) {
			ll a, b; cin >> a >> b;
			dots.push_back({ {a,b},i });
		}
		sort(all(dots));
		sort(dots.begin() + 1, dots.end(), [](const Dot& a, const Dot& b) {
			pll l = a.d, r = b.d;
			int t = ccw(dots[0].d, l, r);
			if (t == 0) return dist(dots[0].d, l) < dist(dots[0].d, r);
			return 0 < t;
		});

		int idx = dots.size() - 1;
		while (idx > 1 && ccw(dots[0].d, dots[idx - 1].d, dots[idx].d) == 0) {
			idx--;
		}

		reverse(dots.begin() + idx, dots.end());

		for (const auto& i : dots) {
			cout << i.idx << ' ';
		}
		if (T != 0) cout << endl;

	}

}