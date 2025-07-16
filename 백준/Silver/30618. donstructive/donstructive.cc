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

ll check(const vector<int>&v) {
	ll res = 0;
	FOR(i, 0, v.size()) {
		ll now = 0;
		FOR(j, i, v.size()) {
			now += v[j];
			res += now;
		}
	}
	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	deque<int> dq;
	for(int i=N;i>0;i--) {
		if (i & 1) {
			dq.push_back(i);
		}
		else {
			dq.push_front(i);
		}
	}

	while (dq.size()) {
		cout << dq.front() << ' ';
		dq.pop_front();
	}

}
