
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using ii = pair<int, int>;

#define For(i,a,b) for(int i=a;i<b;i++)
#define outside(x,y,R,C) (min(x,y) < 0 || x >=R || y >= C)
#define FAST (cin.tie(0)->sync_with_stdio(0))
#define nx(x,i) ("0121"[i] - '1' + x)
#define ny(y,i) ("1210"[i] - '1' + y)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()


// 양수면 시계, 음수면 반시계
ll ccw(pll a, pll b, pll c) {
	ll t = (a.first - b.first) * (c.second - b.second) - (a.second - b.second) * (c.first - b.first);
	return (t < 0) - (t > 0);
}

ll cccw(pll a, pll b, pll c, pll d) {
	d.first -= c.first - b.first;
	d.second -= c.second - b.second;
	return ccw(a, b, d);
}

double dist(pll a, pll b) {
	return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

vector<pll> dots;
vector<pll> ch;

int cmp1(const pll& a, const pll& b) {
	if (a.first != b.first) return a.first < b.first;
	return a.second < b.second;
}

// 시계 방향 정렬
int cmp2(const pll& a, const pll& b) {
	int t = ccw(dots[0], a, b);
	if (t != 0) return t > 0;
	return dist(dots[0], a) < dist(dots[0], b);
}

int main() {

	cin.tie(0)->sync_with_stdio(0);


	dots.clear();
	ch.clear();

	int C; cin >> C;
	For(i, 0, C) {
		ll a, b; cin >> a >> b;
		a *= 1e6; b *= 1e6;
		dots.push_back({ a,b });
	}

	sort(all(dots), cmp1);
	sort(dots.begin() + 1, dots.end(), cmp2);

	/*for (auto& i : dots) {
		cout << i.first << ' ' << i.second << endl;
	}*/

	// convex hull
	for (auto& d : dots) {
		if (ch.size() < 2) {
			ch.push_back(d); continue;
		}
		while (ch.size() >= 2 && ccw(ch[ch.size() - 2], ch[ch.size() - 1], d) <= 0) ch.pop_back();
		ch.push_back(d);
	}

	pll a, b;
	double far = 0;
	int opp = 1;
	For(i, 0, ch.size()) {
		while (opp + 1 != i && cccw(ch[i], ch[(i + 1) % ch.size()], ch[opp % ch.size()], ch[(opp + 1) % ch.size()])>0) {
			if (far < dist(ch[i], ch[opp % ch.size()])) {
				far = dist(ch[i], ch[opp % ch.size()]);
				a = ch[i]; b = ch[opp % ch.size()];
			}
			opp++;
		}
		if (far < dist(ch[i], ch[opp % ch.size()])) {
			far = dist(ch[i], ch[opp % ch.size()]);
			a = ch[i]; b = ch[opp % ch.size()];
		}
	}

	cout << setprecision(9) << fixed << far / 1e6;


}
