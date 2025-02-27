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


map<int, set<int>> problems;
int diff[111'111];

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	FOR(i, 0, N) {
		int p, l; cin >> p >> l;
		problems[l].insert(p);
		diff[p] = l;
	}

	int M; cin >> M;

	while (M--) {
		string s; cin >> s;
		if(s[0] == 'r') {
			int x; cin >> x;
			if (x == 1) {
				auto& p = *problems.rbegin();
				cout << *p.second.rbegin() << endl;
			}
			else {
				auto& p = *problems.begin();
				cout << *p.second.begin() << endl;
			}
		}
		else if (s[0] == 'a') {
			int p, l; cin >> p >> l;
			problems[l].insert(p);
			diff[p] = l;
		}
		else {
			int p; cin >> p;
			auto& se = problems[diff[p]];
			se.erase(p);
			if (se.empty()) {
				problems.erase(diff[p]);
			}
		}
	}

}
