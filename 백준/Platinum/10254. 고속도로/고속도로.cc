#include <bits/stdc++.h>
using namespace std;

#define For(i,a,b) for(int i=a;i<b;i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using pii = pair<int, int>;
using ll = long long;

struct Dot {
	ll x, y;
};

vector<Dot> dots;
vector<Dot> convex;

// 시계면 양수, 반시계면 음수, 직선이면 0 반환
ll ccw(Dot a, Dot m, Dot b) {
	// t가 양수면 반시계, 음수면 시계, 0이면 직선
	ll t = (a.x - m.x) *(b.y - m.y) - (a.y - m.y) *(b.x - m.x);
	return (t < 0) - (t > 0);
}

ll dist(Dot a, Dot b) {
	return pow((a.x - b.x), 2) + pow((a.y - b.y), 2);
}

// 좌표순 정렬. 제일 좌측, 제일 그 중 제일 하단의 점이 먼저 옴
int cmp1(const Dot& l, const Dot& r) {
	if (l.x != r.x) return l.x < r.x;
	return l.y < r.y;
}

// 컨벡스 정렬
// 시계방향으로 정렬됨. 직선이라면, x가 작은 게 먼저 오도록 함
int cmp2(const Dot& l, const Dot& r) {
	int tmp = ccw(dots[0], l, r);
	if (tmp != 0) return tmp > 0;
	return dist(dots[0], l) < dist(dots[0], r);
}

// 선 CD를 AB에 붙여서 CCW
ll cccw(Dot a, Dot b, Dot c, Dot d) {
	d.x -= c.x - b.x;
	d.y -= c.y - b.y;
	return ccw(a, b, d);
}

/*

회전하는 캘리퍼스

시계방향 순서로 점 AB와 CD를 잡는다.

AB와 CD가 시계를 이루는 동안 CD를 한 칸씩 이동한다.
이후 B와 C 사이의 거리를 잰다.

AB가 원래 위치로 돌아올 때까지 위 과정을 반복함.

시간복잡도는 O(N)

*/

int main() {

	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;

	while (T--) {

		dots.clear();
		convex.clear();

		int N; cin >> N;

		For(i, 0, N) {
			ll a, b; cin >> a >> b;
			dots.push_back({ a,b });
		}
		sort(all(dots), cmp1);
		sort(dots.begin() + 1, dots.end(), cmp2);

		// convex hull
		for (auto& dot : dots) {
			if (convex.size() < 2) {
				convex.push_back(dot); continue;
			}
			while (convex.size() >= 2 && ccw(convex[convex.size() - 2], convex[convex.size() - 1], dot) <= 0) {
				convex.pop_back();
			}
			convex.push_back(dot);
		}

		int opposite = 1;
		ll res = 0;
		Dot l, r;
		for (int i = 0; i < convex.size(); i++) {
			while (opposite + 1 != i && cccw(convex[i], convex[(i + 1) % convex.size()], convex[opposite % convex.size()], convex[(opposite + 1) % convex.size()]) > 0) {
				if (res < dist(convex[i], convex[opposite%convex.size()])) {
					res = dist(convex[i], convex[opposite%convex.size()]);
					l = convex[i]; r = convex[opposite%convex.size()];
				}
				opposite++;
			}
			if (res < dist(convex[i], convex[opposite%convex.size()])) {
				res = dist(convex[i], convex[opposite%convex.size()]);
				l = convex[i]; r = convex[opposite%convex.size()];
			}
		}

		cout << l.x << ' ' << l.y << ' ' << r.x << ' ' << r.y << endl;
	}

}