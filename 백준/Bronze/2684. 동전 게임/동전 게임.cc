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

	int T; cin >> T;

	vector<string> v;
	FOR(i, 0, 8) {
		string now;
		for (int k = 2; k >= 0; k--) {
			if ((1 << k) & i) {
				now.push_back('H');
			}
			else now.push_back('T');
		}
		v.push_back(now);
	}


	while (T--) {
		string s; cin >> s;
		vector<int> res(8);
		FOR(i, 0, s.size() - 2) {
			string now = s.substr(i, 3);
			FOR(j, 0, 8) {
				res[j] += v[j] == now;
			}
		}

		for (int r : res) cout << r << ' ';
		cout << endl;
	}

}
