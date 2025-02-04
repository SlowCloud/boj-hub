#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
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

	ll L, N, K; cin >> L >> N >> K;

	if (N >= K) {
		FOR(i, 0, K) {
			cout << "0 ";
		}
		return 0;
	}

	unordered_set<ll> vst;
	queue<ll> q;

	FOR(i, 0, N) {
		ll n; cin >> n;
		vst.insert(n); q.push(n);
	}

	vector<ll> res(N, 0);
	ll dep = 0;
	while (res.size() < K) {
		dep++;
		for (ll t = q.size(); t--;) {
			ll now = q.front(); q.pop();
			for (ll next : {now - 1, now + 1}) {
				if (next < 0ll || next > L) continue;
				if (vst.count(next)) continue;
				vst.insert(next);
				q.push(next);
				res.push_back(dep);
			}
		}
	}

	FOR(i, 0, K) {
		cout << res[i] << ' ';
	}

}
