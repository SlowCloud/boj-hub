#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
#define rall(v) v.rbegin(), v.rend()
#define PI 3.141592653589793


// https://www.acmicpc.net/problem/14899

struct Node {
	double mx, mn, sum;
};

vector<Node> seg(800'001);
vector<ll> arr(200'001), lsum(800'001), lazydiv(800'001);
int N;

Node f(Node a, Node b) {
	return { max(a.mx, b.mx), min(a.mn, b.mn), a.sum + b.sum };
}

void init(int n = 1, int s = 1, int e = N) {
	if (s == e) {
		seg[n] = { (double)arr[s], (double)arr[s], (double)arr[s] };
		return;
	}

	int m = s + e >> 1;

	init(n << 1, s, m);
	init(n << 1 | 1, m + 1, e);

	seg[n] = f(seg[n << 1], seg[n << 1 | 1]);
}

void prop(int n, int s, int e) {

	if (lazydiv[n] != -INF) {
		seg[n].mx = seg[n].mn = lazydiv[n] + lsum[n];
		seg[n].sum = seg[n].mx * ((ll)e - s + 1);

		if (s ^ e) {
			lazydiv[n << 1] = lazydiv[n];
			lazydiv[n << 1 | 1] = lazydiv[n];
			lsum[n << 1] = lsum[n];
			lsum[n << 1 | 1] = lsum[n];
		}

		lazydiv[n] = -INF;
		lsum[n] = 0;
	}
	else {
		seg[n].sum += lsum[n] * ((ll)e - s + 1);
		seg[n].mx += lsum[n];
		seg[n].mn += lsum[n];

		if (s ^ e) {
			lsum[n << 1] += lsum[n];
			lsum[n << 1 | 1] += lsum[n];
		}

		lsum[n] = 0;
	}

}

void add(int l, int r, int v, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l) return;
	if (l <= s && e <= r) {
		lsum[n] = v; prop(n, s, e); return;
	}

	int m = s + e >> 1;

	add(l, r, v, n << 1, s, m);
	add(l, r, v, n << 1 | 1, m + 1, e);

	seg[n] = f(seg[n << 1], seg[n << 1 | 1]);
}

void div(int l, int r, int v, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l) return;
	if (l <= s && e <= r) {

		// 나누었을 때 같은 수라면
		if (floor(seg[n].mx / v) == floor(seg[n].mn / v)) {
			lazydiv[n] = floor(seg[n].mx / v);
			prop(n, s, e);
			return;
		}

		// 나누었을 때 같은 수가 아닌데 1만 차이가 난다면
		if (seg[n].mx - 1 == seg[n].mn) {
			lsum[n] = floor(seg[n].mn / v) - seg[n].mn;
			prop(n, s, e);
			return;
		}

	}

	int m = s + e >> 1;

	div(l, r, v, n << 1, s, m);
	div(l, r, v, n << 1 | 1, m + 1, e);

	seg[n] = f(seg[n << 1], seg[n << 1 | 1]);
}

ll mx(int l, int r, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l) return -INF;
	if (l <= s && e <= r) return seg[n].mx;

	int m = s + e >> 1;

	return max(mx(l, r, n << 1, s, m), mx(l, r, n << 1 | 1, m + 1, e));
}

ll sum(int l, int r, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l) return 0;
	if (l <= s && e <= r) return seg[n].sum;

	int m = s + e >> 1;

	return sum(l, r, n << 1, s, m) + sum(l, r, n << 1 | 1, m + 1, e);
}


int main() {
	FAST; NOTIE;

	int Q; cin >> N >> Q;

	for (int i = 1; i <= N; i++) cin >> arr[i];
	init();

	for (auto& i : lazydiv) i = -INF;

	while (Q--) {
		int op; cin >> op;
		if (op == 0) {
			int a, b, c; cin >> a >> b >> c;
			add(a + 1, b + 1, c);
		}
		else if (op == 1) {
			int a, b, c; cin >> a >> b >> c;
			div(a + 1, b + 1, c);
		}
		else {
			int a, b, c; cin >> a >> b >> c;
			cout << mx(a + 1, b + 1) << endl;
		}
	}

} // main
