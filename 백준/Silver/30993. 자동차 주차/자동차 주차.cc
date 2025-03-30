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

	int N, A, B, C;
	cin >> N >> A >> B >> C;

	vector<int> v;
	FOR(i, 0, A) v.push_back(0);
	FOR(i, 0, B) v.push_back(1);
	FOR(i, 0, C) v.push_back(2);

	int res = 0;
	do {
		res++;
	} while (next_permutation(all(v)));

	cout << res;

}
