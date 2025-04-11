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


int left(const multiset<int>& ms) {
	return *ms.begin();
}

int right(const multiset<int>& ms) {
	return *ms.rbegin();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, D; cin >> N >> D;

	vector<pii> dots(N);
	FOR(i, 0, N) {
		cin >> dots[i].first >> dots[i].second;
	}
	sort(all(dots));

	multiset<int> ms;

	int res = 1e9;
	int l, r;
	l = 0; r = 0;
	ms.insert(dots[0].second);

	while (true) {
		if (right(ms) - left(ms) >= D) {
			res = min(res, dots[r].first - dots[l].first);
			ms.erase(ms.find(dots[l].second));
			l++;
		}
		else {
			if (r == dots.size() - 1) break;
			r++;
			ms.insert(dots[r].second);
		}
	}

	cout << (res == 1e9 ? -1 : res);

}
