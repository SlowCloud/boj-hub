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


struct Node {
	int band, bor, mx;
};

constexpr int MAX = 5e5;
vector<Node> seg(MAX << 2);
vector<int> arr(MAX), lazy(MAX << 2), land(MAX << 2), lor(MAX << 2);
int N;

Node f(Node a, Node b) {
	return { a.band & b.band, a.bor | b.bor, min(a.mx, b.mx) };
}

void init(int n = 1, int s = 1, int e = N) {
	if (s == e) {
		seg[n] = { arr[s], arr[s], arr[s] };
		return;
	}

	int m = s + e >> 1;

	init(n << 1, s, m);
	init(n << 1 | 1, m + 1, e);

	seg[n] = f(seg[n << 1], seg[n << 1 | 1]);
}

void prop(int n, int s, int e) {

	// lazy 갱신이 필요할 때.
	if (lazy[n] != -1) {
		lazy[n] = lazy[n] & land[n] | lor[n];
		seg[n].band = seg[n].bor = seg[n].mx = lazy[n];

		if (s ^ e) {
			lazy[n << 1] = lazy[n];
			lazy[n << 1 | 1] = lazy[n];

			land[n << 1] = land[n << 1 | 1] = -1;
			lor[n << 1] = lor[n << 1 | 1] = 0;
		}

		lazy[n] = -1;
		land[n] = -1, lor[n] = 0;
	}

	// land, lor만 할 때.
	else if (land[n] != -1 || lor[n] != 0) {
		seg[n].band = seg[n].band & land[n] | lor[n];
		seg[n].bor = seg[n].bor & land[n] | lor[n];
		seg[n].mx = seg[n].mx & land[n] | lor[n];

		if (s ^ e) {
			lor[n << 1] = lor[n << 1] & land[n] | lor[n];
			lor[n << 1 | 1] = lor[n << 1 | 1] & land[n] | lor[n];
			land[n << 1] = land[n << 1] & land[n] | lor[n];
			land[n << 1 | 1] = land[n << 1 | 1] & land[n] | lor[n];
		}

		land[n] = -1, lor[n] = 0;
	}

}

void andupdate(int l, int r, int v, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l || seg[n].bor == (seg[n].bor & v)) return;
	if (l <= s && e <= r) {

		// 모든 값이 동일하다면 바로 갱신
		if (seg[n].band == seg[n].bor) {
			lazy[n] = (v & seg[n].band); prop(n, s, e); return;
		}

		// v가 모든 구간 and값 안이라면 갱신
		if (seg[n].band == (seg[n].band | v)) {
			lazy[n] = v; prop(n, s, e); return;
		}

		// and를 제외한 or 구간을 v가 모두 포함한다면
		if (((seg[n].bor - seg[n].band) | v) == v) {
			land[n] = v;
			prop(n, s, e); return;
		}

		// 한 비트도 안 겹치면 바로 0으로. 이건 잘 됨
		if (!(seg[n].bor & v)) {
			lazy[n] = 0; prop(n, s, e); return;
		}

	}

	int m = s + e >> 1;

	andupdate(l, r, v, n << 1, s, m);
	andupdate(l, r, v, n << 1 | 1, m + 1, e);

	seg[n] = f(seg[n << 1], seg[n << 1 | 1]);
}

void orupdate(int l, int r, int v, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l || v == (seg[n].band & v)) return;
	if (l <= s && e <= r) {

		// 모든 값이 동일하다면 바로 갱신
		if (seg[n].band == seg[n].bor) {
			lazy[n] = (v | seg[n].bor); prop(n, s, e); return;
		}

		// 현재 구간의 모든 값과 or한 결과가 v와 같다면 갱신
		if (v == (seg[n].bor | v)) {
			lazy[n] = v; prop(n, s, e); return;
		}

		// and를 제외한 or 값들을 v가 모두 포함한다면 갱신
		if (((seg[n].bor - seg[n].band) | v) == v) {
			lor[n] = v; prop(n, s, e); return;
		}

		// and를 제외한 or값이 v와 겹치지 않으면 더하기
		if (v == (v & ~(seg[n].bor - seg[n].band))) {
			lor[n] = v; prop(n, s, e); return;
		}

	}

	int m = s + e >> 1;

	orupdate(l, r, v, n << 1, s, m);
	orupdate(l, r, v, n << 1 | 1, m + 1, e);

	seg[n] = f(seg[n << 1], seg[n << 1 | 1]);
}

int mx(int l, int r, int n = 1, int s = 1, int e = N) {
	prop(n, s, e);

	if (r < s || e < l) return INF;
	if (l <= s && e <= r) return seg[n].mx;

	int m = s + e >> 1;

	return min(mx(l, r, n << 1, s, m), mx(l, r, n << 1 | 1, m + 1, e));
}

int main() {
	FAST; NOTIE;

	cin >> N;

	for (int i = 1; i <= N; i++) cin >> arr[i];
	init();

	int Q; cin >> Q;
	fill(all(lazy), -1);
	fill(all(land), -1);

	while (Q--) {
		char op; cin >> op;
		if (op == '&') {
			int a, b, c; cin >> a >> b >> c;
			andupdate(a, b, c);
		}
		else if (op == '|') {
			int a, b, c; cin >> a >> b >> c;
			orupdate(a, b, c);
		}
		else {
			int a, b; cin >> a >> b;
			cout << mx(a, b) << endl;
		}
	}

} // main
