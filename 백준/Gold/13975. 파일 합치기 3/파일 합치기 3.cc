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


void solve() {

	int N; cin >> N;

	ll res = 0;
	priority_queue<ll, vector<ll>, greater<>> pq;
	FOR(i, 0, N) {
		ll n; cin >> n;
		pq.push(n);
	}

	while (pq.size() > 1) {
		ll a, b;
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		res += a + b;
		pq.push(a + b);
	}

	cout << res << endl;

}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		solve();
	}

}
