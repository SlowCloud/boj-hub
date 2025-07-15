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


map<string, vector<string>> m;

int main() {
	cin.tie(0)->sync_with_stdio(0);


	int N; cin >> N;

	FOR(i, 0, N) {
		string a, b; cin >> a >> b;
		if (b == "-") continue;
		m[b].push_back(a);
	}

	vector<string> rings;
	for (auto& p : m) {
		if (p.second.size() == 2) {
			rings.push_back(p.first);
		}
	}

	cout << rings.size() << endl;

	for (auto& ring : rings) {
			for (auto& name : m[ring]) {
				cout << name << ' ';
			}
			cout << endl;
	}

}
