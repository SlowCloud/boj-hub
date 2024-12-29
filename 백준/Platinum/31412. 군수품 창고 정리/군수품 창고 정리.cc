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

using vll = vector<ll>;

bool calc(const vll& A, const vll& B, const ll cap) {
	ll begin = 0;
	ll l, r, m;
	l = 0, r = A.size() - 1;
	for (ll b : B) {
		l = begin, r = A.size() - 1;
		while (l <= r) {
			m = l + r >> 1;
			ll now = A[m] - (begin ? A[begin - 1] : 0);
			ll n = now / b + (now % b ? 1 : 0);
			if (n <= cap) l = m + 1;
			else r = m - 1;
		}
		begin = l;
		if (begin == A.size()) break;
	}
	return l >= A.size();
}

bool calc2(const vll& A, vll& B, const ll cap) {
	sort(all(B));
	do {
		if (calc(A, B, cap)) return true;
	} while (next_permutation(all(B)));
	return false;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll N, M; cin >> N >> M;
	vector<ll> a(N); for (auto& i : a) cin >> i;
	vector<ll> b(M); for (auto& i : b) cin >> i;
	//sort(rall(b));

	//if (N <= M) {
	//	sort(rall(a));
	//	ll res = 9e18;
	//	FOR(i, 0, N) {
	//		res = min(res, a[i] / b[i] + (a[i] % b[i] ? 1 : 0));
	//	}
	//	cout << res; return 0;
	//}

	FOR(i, 1, a.size()) {
		a[i] += a[i - 1];
	}

	ll l, r, m;
	l = 1, r = 5e12;

	while (l <= r) {
		m = l + r >> 1;
		bool check = calc2(a, b, m);
		if (check) r = m - 1;
		else l = m + 1;
	}

	cout << l;

}
