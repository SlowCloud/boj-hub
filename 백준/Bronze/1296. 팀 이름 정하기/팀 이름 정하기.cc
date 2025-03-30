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


map<char, int> cnt;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	string s; cin >> s;
	string love = "LOVE";
	set<char> exist(all(love));

	int N; cin >> N;

	vector<pair<int, string>> res;

	FOR(i, 0, N) {
		string now; cin >> now;
		cnt.clear();
		for (char c : now) {
			if (exist.count(c)) {
				cnt[c]++;
			}
		}
		for (char c : s) {
			if (exist.count(c)) {
				cnt[c]++;
			}
		}
		int score = 1;
		FOR(i, 0, love.size()) {
			FOR(j, i + 1, love.size()) {
				score *= (cnt[love[i]] + cnt[love[j]]);
				score %= 100;
			}
		}
		res.push_back({ -score, now });
	}

	sort(all(res));
	cout << res[0].second;

}
