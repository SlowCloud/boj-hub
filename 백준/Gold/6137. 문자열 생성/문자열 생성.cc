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

	int N; cin >> N;

	vector<char> v(N);
	for (auto& c : v) cin >> c;
	
	string res;
	int l = 0, r = v.size() - 1;
	while (l <= r) { // O(N^2)
		if (char tmp = min(v[l], v[r]); v[l] != v[r]) {
			res.push_back(tmp);
			l += v[l] == tmp;
			r -= v[r] == tmp;
		}
		else {
			bool flag = false;
			for (int ll = l, rr = r; ll < rr; ll++, rr--) {
				if (v[ll] == v[rr]) continue;
				flag = v[ll] <= v[rr];
				break;
			}
			if(flag) {
				res.push_back(v[l]); l++;
			}
			else {
				res.push_back(v[r]); r--;
			}
		}
	}
	FOR(i, 0, res.size()) {
		if (i && i % 80 == 0) {
			cout << endl;
		}
		cout << res[i];
	}

}
