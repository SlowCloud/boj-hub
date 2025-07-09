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



int a[1'111'111][2]; // happy // should desc
// 0: 0~i min
// 1: i~N-1 max
int b[1'111'111][2]; // sad // should asc
// 0: 0~i max
// 1: i~N-1 min

bool check_a(int i) {
	return a[i][0] > a[i + 1][1];
}

bool check_b(int i) {
	return b[i][0] < b[i + 1][1];
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 0, N) {
		int u, v; cin >> u >> v;
		a[i][0] = a[i][1] = u;
		b[i][0] = b[i][1] = v;
	}

	// if (a[0][0] == 0) a[0][0] = 1e9;
	// if (a[N - 1][1] == 0) a[N - 1][1] = 1;

	// if (b[0][0] == 0) b[0][0] = 1;
	// if (b[N - 1][1] == 0) b[N - 1][1] = 1e9;

	if (a[0][0] == 0) a[0][0] = 2e9;
	if (a[N - 1][1] == 0) a[N - 1][1] = 0;

	if (b[0][0] == 0) b[0][0] = 0;
	if (b[N - 1][1] == 0) b[N - 1][1] = 2e9;

	FOR(i, 1, N) {
		if (a[i][0] == 0) {
			a[i][0] = a[i - 1][0];
		}
		else {
			a[i][0] = min(a[i][0], a[i - 1][0]);
		}
		if (b[i][0] == 0) {
			b[i][0] = b[i - 1][0];
		}
		else {
			b[i][0] = max(b[i][0], b[i - 1][0]);
		}
	}
	for (int i = N - 2; i >= 0; i--) {
		if (a[i][1] == 0) {
			a[i][1] = a[i + 1][1];
		}
		else {
			a[i][1] = max(a[i][1], a[i + 1][1]);
		}
		if (b[i][1] == 0) {
			b[i][1] = b[i + 1][1];
		}
		else {
			b[i][1] = min(b[i][1], b[i + 1][1]);
		}
	}

	int res = -1;
	for (int i = N - 2; i >= 0; i--) {
		if (check_a(i) && check_b(i)) {
			res = i + 1; break;
		}
	}

	cout << res;

}
