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


/*

1
1 2
1 3
1 2 4
1 5
1 2 3 6
1 7
1 2 4 8
1 3 9
1 2 5 10
1 11
1 2 3 4 6 12
1 13
1 2 7 14
1 3 5 15

...

1 3 9 27
1 3 9 27 81

*/

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;
	while (N--) {
		ll n; cin >> n;
		ll sq = sqrt(n);
		cout << (sq * sq == n) << endl;

	}

}

