#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <unordered_set>
#include <regex>
using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;

#define FOR(i,a,b) for(int i=a;i<b;i++)
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()



int main() {
	cin.tie(0)->sync_with_stdio(0);
 
	cout << "YES" << endl;

	int N; cin >> N;

	deque<int> a, b;

	a.push_back(N);

	int u = 1;

	FOR(i, 1, N) {
		if (i & 1) {
			a.push_back(u++);
		}
		else {
			a.push_front(u++);
		}
	}

	int l = 1, r = a.size();
	while (l < r) {
		if (a.size() & 1) {
			b.push_back(l++);
			b.push_back(r--);
		}
		else {
			b.push_back(r--);
			b.push_back(l++);
		}
	}
	if (l == r) b.push_back(l);

	for (const auto& i : a) cout << i << ' '; cout << endl;
	for (const auto& i : b) cout << i << ' '; cout << endl;

}
