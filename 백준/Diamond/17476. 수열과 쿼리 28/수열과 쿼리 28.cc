
#include <bits/stdc++.h>
#include <unordered_set>
#include <unordered_map>
#include <random>

using namespace std;

#define FAST ios::sync_with_stdio(0);
#define NOTIE cin.tie(0);
constexpr int INF = 2e9;
constexpr long long LLINF = 9e18;

#define endl '\n'
typedef long long ll;
typedef pair<int, int> ii;
#define all(v) v.begin(), v.end()


struct Node {
	ll mx, mn, sum;
};

Node f(Node& a, Node& b) {
	return { max(a.mx, b.mx), min(a.mn, b.mn), a.sum + b.sum };
}

vector<Node> seg(1 << 18);
vector<ll> lazysum(1 << 18), lazysqrt(1 << 18);
int N;

void prop(int n, int s, int e) {

	if (!lazysum[n] && !lazysqrt[n]) return;

	if (!lazysqrt[n]) {

		seg[n].mx += lazysum[n];
		seg[n].mn += lazysum[n];
		seg[n].sum += lazysum[n] * (e - s + 1);

		if (s ^ e) {
			lazysum[n << 1] += lazysum[n];
			lazysum[n << 1 | 1] += lazysum[n];
		}
	}
	else {
		seg[n].mx = seg[n].mn = lazysum[n] + lazysqrt[n];
		seg[n].sum = (lazysum[n] + lazysqrt[n]) * (e - s + 1);

		if (s ^ e) {
			lazysum[n << 1] = lazysum[n];
			lazysum[n << 1 | 1] = lazysum[n];
			lazysqrt[n << 1] = lazysqrt[n];
			lazysqrt[n << 1 | 1] = lazysqrt[n];
		}
	}

	lazysqrt[n] = lazysum[n] = 0;
}

void add(int l, int r, ll v, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l) return;

	// 범위 안에 들어오면, 자식 노드들의 lazy에 더할 값을 추가하고 빠져나온다.
	if (l <= s && e <= r) {
		lazysum[n] = v;
		prop(n, s, e); return;
	}

	int m = s + e >> 1;

	add(l, r, v, n << 1, s, m);
	add(l, r, v, n << 1 | 1, m + 1, e);

	seg[n] = f(seg[n << 1], seg[n << 1 | 1]);
}

void sq(int l, int r, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	// 최대가 0이면 sqrt해도 값이 같으므로 멈춤.
	if (r < s || e < l) return;

	// 최대와 최소를 각각 sqrt한 값이 같다면 업데이트!
	if (l <= s && e <= r) {
		if (floor(sqrt(seg[n].mx)) == floor(sqrt(seg[n].mn))) {
			lazysqrt[n] = floor(sqrt(seg[n].mx));
			prop(n, s, e); return;
		}
		if (seg[n].mn + 1 == seg[n].mx) {
			lazysum[n] = floor(sqrt(seg[n].mn)) - seg[n].mn;
			prop(n, s, e); return;
		}
	}

	int m = s + e >> 1;

	sq(l, r, n << 1, s, m);
	sq(l, r, n << 1 | 1, m + 1, e);

	seg[n] = f(seg[n << 1], seg[n << 1 | 1]);
}

ll query(int l, int r, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[n].sum;

	int m = s + e >> 1;

	return query(l, r, n << 1, s, m) + query(l, r, n << 1 | 1, m + 1, e);
}

int main() {
	FAST; NOTIE;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		ll n; cin >> n;
		add(i, i, n);
	}

	int Q; cin >> Q;
	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int a, b, c; cin >> a >> b >> c;
			add(a, b, c);
		}
		else if (op == 2) {
			int a, b; cin >> a >> b;
			sq(a, b);
		}
		else {
			int a, b; cin >> a >> b;
			cout << query(a, b) << endl;
		}
	}

} // main

// 계속 안되서 풀이 보고 다시 짰는데 똑같은 오답이 나오는데?
// 아이디어는 다 똑같아서 뭐가 틀렸나 싶어서 따라짰는데 계속 틀린 답이 나오는데 뭐지
// 혹시 bias를 N이랑 같게 만들어서 그런가?
// 84번째 줄 l을 1로 적었구나 ㅁㄴㅇㄻㄴㅇㄻㄴㅇㄹ 다풀었던 거네
