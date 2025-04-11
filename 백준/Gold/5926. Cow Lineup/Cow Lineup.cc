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

	int N; cin >> N;

	if (N == 1) {
		cout << 0; exit(0);
	}

	vector<pii> v;
	set<int> s;
	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		v.push_back({ a,b });
		s.insert(b);
	}
	sort(all(v));

	map<int, int> cnt;
	int now = 0;
	int l = 0;
	int res = 2e9;

	cnt[v[0].second]++;
	now = 1;

	FOR(i, 1, N) {
		if (cnt[v[i].second]++ == 0) {
			now++;
		}
		if (now == s.size()) {
			while(cnt[v[l].second] > 1) {
				cnt[v[l].second]--;
				l++;
			}
			res = min(res, v[i].first - v[l].first);
			while(now == s.size()) {
				if (--cnt[v[l++].second] == 0) {
					now--;
				}
			}
		}
	}

	cout << res;

}
