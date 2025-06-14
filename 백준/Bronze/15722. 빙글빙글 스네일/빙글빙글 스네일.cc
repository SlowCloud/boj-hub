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

	int x, y;
	x = y = 0;

	int d = 0;
	int size = 1;
	int step = 0;
	int cnt = 0;

	int N; cin >> N;

	while(N--) {

		x += "2101"[d] - '1';
		y += "1210"[d] - '1';

		step++;
		if (step == size) {
			step = 0;
			d = (d + 1) % 4;
			cnt++;
		}

		if (cnt == 2) {
			cnt = 0; size++;
		}

	}

	cout << y << ' ' << x;

}
