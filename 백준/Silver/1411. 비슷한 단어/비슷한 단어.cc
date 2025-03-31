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


string convert(const string s) {
	string res;

	map<char, int> m;
	int number = 0;

	for (char c : s) {
		if (m.find(c) == m.end()) {
			m[c] = number++;
		}
		res.push_back(m[c] + 'a');
	}

	return res;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	int N; cin >> N;

	map<string, int> cnt;

	FOR(i, 0, N) {
		string s; cin >> s;
		cnt[convert(s)]++;
	}

	int res = 0;
	for (auto& p : cnt) {
		int now = p.second;
		res += now * (now - 1) / 2;
	}

	cout << res;

}

