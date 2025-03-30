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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;


	if (N == 1) {
		cout << 1; return 0;
	}

	if (N == 2) {
		if (M >= 7) {
			cout << 4; return 0;
		}
		else {
			cout << 1 + (M - 1) / 2; return 0;
		}
	}

	if (N >= 3) {
		if (M <= 6) {
			cout << min(4, M); return 0;
		}
		else {
			cout << M - 2; return 0;
		}
	}


}
