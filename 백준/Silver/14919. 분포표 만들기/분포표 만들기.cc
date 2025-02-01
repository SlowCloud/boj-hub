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

constexpr ll GAP = 1e9;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	ll M; cin >> M;
	ll L = GAP / M;

	vector<ll> v;
	string n;
	while (cin >> n) {
		n = n.substr(2);
		n += string(max(0, 9 - (int)n.size()), '0');
		v.push_back(stoll(n));
	}

	sort(all(v));
	int idx = 0;
	ll nowL = 0;
	FOR(i, 0, M) {
		nowL += L;
		int now = 0;
		while (idx < v.size() && v[idx] < nowL) now++, idx++;
		cout << now << ' ';
	}

}
