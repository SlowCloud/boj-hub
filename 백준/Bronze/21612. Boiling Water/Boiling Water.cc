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

int res = 0;
int N, K;

set<int> dp;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int B; cin >> B;

	int P = 5 * B - 400;


	cout << P << endl;

	if (P < 100) cout << 1;
	if (P == 100) cout << 0;
	if (P > 100) cout << -1;


}