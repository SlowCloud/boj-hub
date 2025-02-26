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


	vector<string> res;

	constexpr auto build = [](int n) -> string {
		string res = "";
		for (int i = 3; i >= 0; i--) {
			if (n & (1 << i)) {
				res += "딸기";
			}
			else {
				res += 'V';
			}
		}
		return res;
	};

	int tmp = 0;
	FOR(i, 0, 15) {
		tmp++;
		res.push_back(build(tmp));
	}
	FOR(i, 0, 13) {
		tmp--;
		res.push_back(build(tmp));
	}

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		n--;
		n %= res.size();
		cout << res[n] << endl;
	}

}
