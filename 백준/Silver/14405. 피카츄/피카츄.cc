#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
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

	string s; cin >> s;

	int idx = 0;
	while (idx < s.size()) {
		string two = s.substr(idx, 2);
		string three = s.substr(idx, 3);

		bool flag = false;
		if (two == "pi" || two == "ka") {
			idx += 2;
			flag = true;
		}
		if (three == "chu") {
			idx += 3;
			flag = true;
		}
		if (!flag) {
			cout << "NO" << endl; return 0;
		}
	}
	cout << "YES" << endl;

}