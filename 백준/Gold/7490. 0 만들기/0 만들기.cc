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


vector<string> v;
string res;

void dfs(int idx, int top, ll now) {
	if (idx > top) {
		if (now == 0) {
			v.push_back(res);
		}
		return;
	}
	ll tmp;
	if(idx > 1) res.push_back('+');
	tmp = 0;
	FOR(i, idx, top + 1) {
		tmp = tmp * 10 + i;
		if(i != idx) res.push_back(' ');
		res.push_back('0' + i);
		int cnt = i - idx + 1;
		dfs(idx + cnt, top, now + tmp);
	}
	FOR(i, idx, top) res.pop_back(), res.pop_back();
	res.pop_back();
	if(idx > 1) res.pop_back();

	if (idx == 1) return;
	res.push_back('-');
	tmp = 0;
	FOR(i, idx, top + 1) {
		tmp = tmp * 10 + i;
		if(i != idx) res.push_back(' ');
		res.push_back('0' + i);
		int cnt = i - idx + 1;
		dfs(idx + cnt, top, now - tmp);
	}
	FOR(i, idx, top) res.pop_back(), res.pop_back();
	res.pop_back(); res.pop_back();
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		dfs(1, n, 0);
		sort(all(v));
		for (auto& s : v) {
			cout << s << endl;
		}
		cout << endl;
		v.clear();
	}


}
