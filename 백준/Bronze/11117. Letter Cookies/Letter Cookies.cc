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



int main() {
	cin.tie(0)->sync_with_stdio(0);

	int T; cin >> T;

	while (T--) {

		string s; cin >> s;
		map<char, int> cnt;
		for (char c : s) {
			cnt[c]++;
		}

		int N; cin >> N;

		FOR(i, 0, N) {
			string now; cin >> now;
			map<char, int> now_cnt;
			for (char c : now) {
				now_cnt[c]++;
			}
			bool possible = true;
			for (auto& p : now_cnt) {
				auto [c, n] = p;
				if (cnt.count(c) == 0 || cnt[c] < n) {
					possible = false; break;
				}
			}
			cout << (possible ? "YES" : "NO") << endl;
		}

	}

}

