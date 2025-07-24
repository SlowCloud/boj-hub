#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		int sum = 0;
		int low = 1e9;
		FOR(i, 0, 7) {
			int n; cin >> n;
			if (n % 2) continue;
			sum += n;
			low = min(low, n);
		}

		cout << sum << ' ' << low << endl;

	}

}
