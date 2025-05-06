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



// sum of evens between a

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	ll a, b; cin >> a >> b;

	a = max(a, 4ll);

	if (a > b) {
		cout << 0; exit(0);
	}

	if (a % 2) a++;
	a >>= 1; b >>= 1;

	cout << (b - a + 1) * (a + b);

}

