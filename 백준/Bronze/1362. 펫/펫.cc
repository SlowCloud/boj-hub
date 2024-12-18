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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int nth = 1;
	while (true) {
		int o, w; cin >> o >> w;
		if (o + w == 0) break;

		bool dead = false;

		while(true) {
			char c; int n;
			cin >> c >> n;
			if (c == '#') break;
			if (dead) continue;
			if (c == 'E') {
				w -= n;
			}
			else {
				w += n;
			}
			if (w <= 0) dead = true;
		}

		cout << nth++ << ' ';
		if (dead) {
			cout << "RIP";
		}
		else {
			if (o * 2 > w && w * 2 > o) {
				cout << ":-)";
			}
			else {
				cout << ":-(";
			}
		}
		cout << endl;

	}

}
