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


map<string, set<string>> groups;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N, M; cin >> N >> M;

	FOR(i, 0, N) {
		string s; cin >> s;
		int n; cin >> n;
		FOR(j, 0, n) {
			string name; cin >> name;
			groups[s].insert(name);
		}
	}

	FOR(i, 0, M) {
		string s; cin >> s;
		int n; cin >> n;
		if (n == 0) {
			for (string name : groups[s]) {
				cout << name << endl;
			}
		}
		else {
			for (auto& p : groups) {
				if (p.second.count(s)) {
					cout << p.first << endl;
				}
			}
		}
	}


}

