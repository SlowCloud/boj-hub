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

	int T; cin >> T;

	while (T--) {
		int N, L, K; cin >> N >> L >> K;

		deque<int> a;
		vector<int> p;

		deque<int> l, r;

		FOR(i, 0, N) {
			int u, v; cin >> u >> v;
			a.push_back(v);
			if (v < 0) {
				l.push_back(u + 1);
			}
			else {
				r.push_back(L - u + 1);
			}
		}

		sort(all(l));
		sort(all(r));

		vector<int> res;

		while (l.size() && r.size()) {
			if (l.front() == r.front()) {
				if (a.front() < a.back()) {
					res.push_back(a.front()); a.pop_front(); l.pop_front();
				}
				else {
					res.push_back(a.back()); a.pop_back(); r.pop_front();
				}
			}
			else if (l.front() < r.front()) {
				res.push_back(a.front()); a.pop_front(); l.pop_front();
			}
			else {
				res.push_back(a.back()); a.pop_back(); r.pop_front();
			}
		}

		while (l.size()) {
			res.push_back(a.front()); a.pop_front(); l.pop_front();
		}
		while (r.size()) {
			res.push_back(a.back()); a.pop_back(); r.pop_front();
		}

		cout << res[K - 1] << endl;

	}

}

